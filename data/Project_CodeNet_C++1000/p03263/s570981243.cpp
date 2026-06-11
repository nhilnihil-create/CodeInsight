//

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int h,w;

bool onboard(int a,int b){
    if(a<0||a>=h||b<0||b>=w)return false;
    else return true;
}

signed main (){
    cin>>h>>w;
    vector<vector<int>>a(h,vector<int>(w));
    vector<tuple<int,int,int,int>>ans;
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];
    int il=0,jl=0;
    rep(i,0,h){
        if(i&1){
            for(int j=w-1;j>=0;j--){
                if(a[il][jl]&1){
                    a[il][jl]--;
                    a[i][j]++;
                    ans.pb({il+1,jl+1,i+1,j+1});
                }
                il=i;
                jl=j;
            }
        }else{
            rep(j,0,w){
                if(i==0&&j==0)continue;
                if(a[il][jl]&1){
                    a[il][jl]--;
                    a[i][j]++;
                    ans.pb({il+1,jl+1,i+1,j+1});
                }
                il=i;
                jl=j;
            }
        }
    }
    cout<<ans.size()<<nnn;
    for(auto i:ans){
        cout<<get<0>(i)<<spa<<get<1>(i)<<spa<<get<2>(i)<<spa<<get<3>(i)<<nnn;
    }
    return 0;
}