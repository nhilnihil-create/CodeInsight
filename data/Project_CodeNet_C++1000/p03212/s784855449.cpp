#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define rrep(i,n) for(int i=int(n);i>0;i--)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+5  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
using PPI=pair<P,int>;
//ll const mod=998244353;
ll const mod=1e9+7;
const ll MAX=1000005;
using vi=vector<int>;
using vl=vector<ll>;
using vc=vector<char>;
using vd=vector<double>;
using vs=vector<string>;
using vp=vector<P>;
using vb=vector<bool>;
using vvi =vector<vector<int>>;
using vvl =vector<vector<ll>>;
using vvd=vector<vector<double>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
using vvb=vector<vector<bool>>;
template <typename T>
bool chmax(T &a, const T b){if(a < b){a = b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T b){if(a > b){a = b; return true;} return false;}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
//////////////////////////////////////
int dp[15][9][2];
int main(){
    int n;
    cin>>n;
    vi num;
    while(n>0){
        num.push_back(n%10);
        n/=10;
    }
    reverse(all(num));
    //for(int x:num)cout<<x<<endl;
    n=num.size();
    
    rep(i,n){
        dp[i][0][1]=1;
    }
    dp[0][0][0]=1;
    dp[0][0][1]=0;
    rep(i,n){
        rep(j,8){
            if(num[i]==3){
                dp[i+1][j|0b001][0]+=dp[i][j][0];
            }
            else if(num[i]==5){
                dp[i+1][j|0b010][0]+=dp[i][j][0];
            }
            else if(num[i]==7){
                dp[i+1][j|0b100][0]+=dp[i][j][0];
            }
            
            if(num[i]>3){
                dp[i+1][j|0b001][1]+=dp[i][j][0];
            }
            if(num[i]>5){
                dp[i+1][j|0b010][1]+=dp[i][j][0];
            }
            if(num[i]>7){
                dp[i+1][j|0b100][1]+=dp[i][j][0];
            }
            
            dp[i+1][j|0b001][1]+=dp[i][j][1];
            dp[i+1][j|0b010][1]+=dp[i][j][1];
            dp[i+1][j|0b100][1]+=dp[i][j][1];

            //printf("%d:%d:0=%d\n",i+1,j,dp[i+1][j][0]);
            //printf("%d:%d:1=%d\n",i+1,j,dp[i+1][j][1]);
        }
        
    }
    int ans=dp[n][7][0]+dp[n][7][1];
    cout<<ans<<endl;
    return 0;
}