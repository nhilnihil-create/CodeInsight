#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;


int main() {

    int n,m; cin >> n;
    ll tmp,tmpD,tmpT;
    string ans = "NO";
    priority_queue<ll> d,t;
    rep(i,n){
        cin >> tmp;
        d.push(tmp);
    }
    cin >> m;
    rep(i,m){
        cin >> tmp;
        t.push(tmp);
    }

    while(1) {
        tmpD = d.top();
        tmpT = t.top();
        if(tmpD == tmpT){
            d.pop();t.pop();
        }else if(tmpD > tmpT){
            d.pop();
        }else{
            break;
        }
        if(t.empty()) {
            ans = "YES";
            break;
        }
        if(d.empty()){
            break;
        }
    }
    cout << ans;

    return 0;
}









