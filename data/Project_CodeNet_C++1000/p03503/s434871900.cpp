#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=-100000000000, tmp=0, A[100][10]={{0}}, P[100][11]={{0}};

void dfs(vector<ll> v, ll id) {
    if(id==10) {
        ll flag=0;
        for(int i=0;i<10;i++) {
            if(v[i]==1) flag=1;
        }
        if(flag==0) return;
        tmp=0;
        for(int i=0;i<N;i++) {
            ll ct=0;
            for(int j=0;j<10;j++) {
                if(v[j]==1&&A[i][j]==1) {
                    ct++;
                }
            }
            tmp += P[i][ct];
        }
        ans = max(ans, tmp);
        return;
    }
    dfs(v, id+1);
    v[id]=1;
    dfs(v, id+1);
}

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<10;j++) {
            cin >> A[i][j];
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<11;j++) {
            cin >> P[i][j];
        }
    }
    vector<ll> vemp(10, 0);
    dfs(vemp, 0);
    cout << ans << endl;
    return 0;
}