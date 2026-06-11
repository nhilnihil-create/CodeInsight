#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
    int h,w; cin >> h >> w;
    int g[h][w];
    rep(i,h)rep(j,w) cin >> g[i][j];

    vector<PP> ans;
    int n=0;

    rep(i,h){
        rep(j,w){
            if(i==h-1 && j==w-1) break;
            if(g[i][j]%2==1){
                n++;
                if(j==w-1 && i!=h-1){
                    ans.push_back(PP(P(i+1,j+1),P(i+2,j+1)));
                    g[i+1][j]++;
                }
                else{
                    ans.push_back(PP(P(i+1,j+1),P(i+1,j+2)));
                    g[i][j+1]++;
                }
            }
        }
    }

    cout << n << endl;
    rep(i,ans.size()) cout << ans[i].first.first << ' ' <<  ans[i].first.second << ' ' << ans[i].second.first << ' ' << ans[i].second.second << endl;
return 0;
}