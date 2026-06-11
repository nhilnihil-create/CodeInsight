#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll INF = 1e13;
 
int main(void){
    int n;
    cin>>n;
    vector<vector<int> > v(n);
    rep(i, n) {
        int a;
        cin>>a;
        vector<int>tmp(21);
        int now = 0;
        while(a>0){
            tmp[now] = a%2;
            a/=2;
            now++;
        }
        v[i] = tmp;
    }
    vector<vector<int> >s(21, vector<int>(n+1));
    rep(i, n){
        rep(j, 21){
            s[j][i+1] = s[j][i] + v[i][j];
        }
    }
    ll ans = 0;
    rep(i, n){
        ll now = INF;
        rep(j, 21){
            auto itr = upper_bound(s[j].begin(), s[j].end(), s[j][i]+1);
            int idx = itr-s[j].begin();
            now = min(now, (ll)idx-(ll)i-1);
        }
        ans += now;
    }
    cout<<ans<<endl;
    return 0;
}