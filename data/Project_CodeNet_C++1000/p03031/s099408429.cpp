
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m,vector<int>());
    vector<int> p(m);

    rep(i,m){
        cin >> k[i];
        rep(j,k[i]){
            int S;
            cin >> S;
            s[i].push_back(S);
        }
    }
    rep(i,m) cin >> p[i];

    int ans=0;
    int bit=0;
    for(; bit<(1<<n); bit++){
        int cnt=0;
        rep(i,m){
            int cnton =0;
            rep(j,k[i]){
                int shift = s[i][j] -1;
                if(bit & (1<<shift)) cnton++;
            }
            if(cnton % 2 == p[i]) cnt++;
        }
        if(cnt==m) ans++;
    }
    cout << ans << endl;
    return 0;
}