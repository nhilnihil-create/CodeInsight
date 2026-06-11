#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

int main()
{
    int n,m;
    cin >> n >> m;
    int k;
    vector<vector<int>> s(m,vector<int>(n));
    vector<int> p(m);
    rep(i,m){
        cin >> k;
        s[i].resize(k);
        rep(j,k){
            cin >> s[i][j];
        }
    }

    rep(i,m)cin >> p[i];
    vector<int> bin(n);

    ll ans=0;
    ll count=0;
    ll count_p;
    repl(i,1<<n){
        ll b=i;
        rep(j,n){
            bin[j]=b%2;
            b/=2;
        }
        count_p=0;
        rep(j,m){
            count=0;
            rep(k,s[j].size()){
                if(bin[s[j][k]-1]==1){
                    count++;
                }
            }
            if(count%2==p[j]){
                count_p++;
            }
        }
        if(count_p==m){
            ans++;
        }
    }
    cout << ans << endl;

}