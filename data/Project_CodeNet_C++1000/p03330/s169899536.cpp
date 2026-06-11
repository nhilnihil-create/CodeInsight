//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    int n,c,ans=inf; cin>>n>>c;
    vector<int> x(c,0),y(c,0),z(c,0);
    vector<vector<int>> d(c,vector<int>(c,0));
    rep(i,c){
        rep(j,c){
            cin>>d[i][j];
        }
    } 
    rep(i,n){
        rep(j,n){
            int co; cin>>co; co--;
            if((i+j)%3==0) x[co]++;
            if((i+j)%3==1) y[co]++;
            if((i+j)%3==2) z[co]++;
        }
    } 
    rep(p,c){
        rep(q,c){
            if(q==p) continue;
            rep(r,c){
                if(r==p || r==q) continue;
                int cnt=0;
                rep(i,c){
                    cnt+=x[i]*d[i][p];
                    cnt+=y[i]*d[i][q];
                    cnt+=z[i]*d[i][r];
                }
                ans=min(ans,cnt);
            }
        }
    }
    cout<<ans<<endl;
}