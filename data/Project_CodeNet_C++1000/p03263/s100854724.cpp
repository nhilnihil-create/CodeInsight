#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    int h,w;
    cin>>h>>w;
    int g[h][w];
    rep(i,h)rep(j,w)cin>>g[i][j];
    int n =0;
    vector<int>ans[250001];
    rep(i,h){
        rep(j,w){
            if(g[i][j]%2!=0){
                if(j==w-1&&i==h-1)continue;
                ans[n].push_back(i+1);
                ans[n].push_back(j+1);
                if(j==w-1&&i!=h-1){
                    ans[n].push_back(i+2);
                    ans[n].push_back(j+1);
                    g[i][j]--;
                    g[i+1][j]++;
                }
                else {
                    ans[n].push_back(i+1);
                    ans[n].push_back(j+2);
                    g[i][j]--;
                    g[i][j+1]++;
                }
                n++;
            }
        }
    }
    cout<<n<<endl;
    rep(i,n){
        rep(j,4){
        if(j!=3)cout<<ans[i][j]<<" ";
            else
            {
                cout<<ans[i][j];
            }
        }
        cout<<endl;
    }
}
