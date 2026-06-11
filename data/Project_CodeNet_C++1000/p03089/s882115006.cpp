#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> ans;
    rep(i, n){
        cin >> v[i];
    }

 

    int tmp;
    rep(i, n-1){
        tmp = 0;   
        if(v[0] != 1){
            cout << -1 << endl;
            return 0;
        }
        rep(j, v.size()){
            if(v[j] == j+1){
                tmp = j;
            }
        }

        ans.push_back(v[tmp]);
        v.erase(v.begin()+tmp);
    }

    if(v[0] != 1){
        cout << -1 << endl;
        return 0;
    }
    ans.push_back(1);
    reverse(all(ans));
    for (auto& p : ans) {
        cout << p << endl;
    }

    return 0;
}
