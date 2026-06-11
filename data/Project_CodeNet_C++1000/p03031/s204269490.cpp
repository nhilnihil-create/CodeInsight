#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    Int ans=0;
    vector<vector<int>> s(m);

    for(int i=0; i<m; i++){
        int k; cin>>k;
        for(int j=0; j<k; j++){
            int a; cin>>a;
            a--;
            s[i].push_back(a);
        }
    }
    vector<int> p(m);
    for(int i=0; i<m; i++) cin>>p[i];

    for(int bit=0; bit<(1<<n); ++bit){
        bool ok=true;
        for(int j=0; j<m; j++){
            int con=0;
            for(auto v: s[j]){
                if(bit&(1<<v)) con++;
            }
            if(con%2!=p[j]) ok=false;
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}