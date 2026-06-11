#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }

    vector<pair<ll, ll>> op;

    ll maxi = max_element(a.begin(), a.end()) - a.begin();
    ll mini = min_element(a.begin(), a.end()) - a.begin();
    if(a.at(mini) < 0 && a.at(maxi) > 0){
        if(abs(a.at(mini)) > a.at(maxi)){
            for(int i = 0; i < n; ++i){
                if(a.at(i) > 0){
                    op.push_back(make_pair(mini, i));
                    a.at(i) += a.at(mini);
                }
            }
        }else{
            for(int i = 0; i < n; ++i){
                if(a.at(i) < 0){
                    op.push_back(make_pair(maxi, i));
                    a.at(i) += a.at(maxi);
                }
            }
        }
    }

    ll mina = *min_element(a.begin(), a.end());
    if(mina >= 0){
        for(int i = 1; i < n; ++i){
            if(a.at(i - 1) > a.at(i)){
                op.push_back(make_pair(i - 1, i));
                a.at(i) += a.at(i - 1);
            }
        }
    }else{
        for(int i = n - 2; i >= 0; --i){
            if(a.at(i) > a.at(i + 1)){
                op.push_back(make_pair(i + 1, i));
                a.at(i) += a.at(i + 1);
            }
        }
    }

    cout << op.size() << endl;
    for(auto p : op){
        cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
    return 0;
}