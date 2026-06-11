#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 10101010

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> s(m,vector<int>(n));
    vector<int> p(m);
    vector<int> bit(n);
    vector<int> k_m(m);
    ll count=0;
    ll ans=0;
    ll count_sw=0;
    int k;
    rep(i,m){
        rep(j,n){
            s[i][j]=-1;
        }
    }
    rep(i,m){
        cin >> k_m[i];

        rep(j,k_m[i]){
            cin >> s[i][j];
        }
    }
    rep(i,m)cin >> p[i];

    rep(i,(1<<n)){
        rep(j,n){
            int div=(1<<j);
            bit[j]=(i/div)%2;
        }
        rep(j,m){
            for(int l=0;l<k_m[j];++l){
                if(bit[s[j][l]-1]==1)
                    count_sw++;
                    
                
            }
            if(count_sw%2==p[j]%2){
                count++;
            }else{
                count_sw=0;
                count=0;
                break;
            }
            count_sw=0;
        }
        if(count==m){
            ans++;
            count=0;
            count_sw=0;
        }else{
            count=0;
            count_sw=0;
        }
    }
    cout << ans << endl;
}