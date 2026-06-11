#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m;
    cin >> n>> m;
    vector<int> a(n);
    for(int i=0 ;i<n; i++){
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    vector<pair<int,int>> ope;
    for(int i=0; i<m; i++){
        int b,c;
        cin >> b >> c;
        pair<int, int> p;
        p = make_pair(c,b);
        ope.push_back(p);
    }
    sort(ope.begin(), ope.end());
    reverse(ope.begin(), ope.end());
    int count = 0;
    bool finish = false;
    for(int i=0; i<m; i++){
        pair<int, int> p;
        p = ope.at(i);
        int b,c;
        b= p.second;
        c = p.first;
        int time=0;
        while(time<b){
            if(c >= a.at(count)){
                a.at(count) = c;
                count++;
                time++;
            }
            else{
                finish = true;
                break;
            }
            if(count == n){
                finish=true;
                break;
            }
        }
        if(finish) break;
    }

    ll ans = 0;
    for(int i=0; i<n; i++){
        ans += (ll)a.at(i);
        //cout << a.at(i) << endl;
    }
    cout << ans << endl;
}
