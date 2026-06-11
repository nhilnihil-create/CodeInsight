#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define IO ios::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#define debug(x) cout<<x<<'\n'
#define pii pair<ll,pair<ll,ll> >
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
const double eps = 1e-6;
ll gcd(ll a, ll b) {return b==0?a:gcd(b, a%b);}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}
ll mul(ll a,ll b){ll ans=0;a%=mod,b%=mod;while(b) { if(b&1) ans = (ans+a)%mod; a = (a*2)%mod; b >>= 1; }return ans;}
ll powmod(ll a,ll b){ ll ans = 1, pow = a; while(b) { if(b&1) ans = (ans*pow)%mod; pow = (pow*pow)%mod; b >>= 1; } return ans;}
//(b/a)%p=b*a^(p-2)%p
//int pr(ll num){//判素
//     if(num == 1) return 0;
//     if(num ==2|| num==3 ) return 1 ;
//     if(num %6!= 1&&num %6!= 5) return 0 ;
//     int tmp =sqrt( num);
//     for(int i= 5;i <=tmp; i+=6 )
//          if(num %i== 0||num %(i+ 2)==0 )return 0 ;
//     return 1 ;
//}
int Day(int y,int m, int d){if(m==1||m==2) { m+=12; y--; }int w=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;return w+1;}
//int pri[10000005];
//void getpri(){
//    memset(pri,true,sizeof(pri));
//    pri[0]=pri[1]=0;
//    for(int i=2;i<=10000000;i++){
//        if(pri[i]){
//            for(int j=2*i;j<=10000000;j+=i) pri[j]=0;
//        }
//    }
//}
//struct ac{
//    int x,y;
//    int fa;
//} pre[10000005];
//void init(){
//    for(int i=1; i<=10000005;++i) pre[i].fa=i;
//}
//int getf(int x){
//    if(pre[x].fa == x) return x;
//    else return pre[x].fa = getf(pre[x].fa);
//}
//void join(int x,int y){
//    int a = getf(x);
//    int b = getf(y);
//    if(a!=b) pre[b].fa=a;
//}
//大小写转换
//String s;
//Form(s.begin(),s.end(),s.begin(),::toupper);
//Form(s.begin(),s.end(),s.begin(),::tolower);
//(char)toupper('a')
//(char)tolower('B')
//#pragma comment(linker, "/STACK:1024000000,1024000000")//外挂开栈
//stable_sort 排序不处理相同元素
//map<int,int>::reverse_iterator rit;
//for(rit=mp.rbegin();rit!=mp.rend();rit++)
//vec动态二维数组
//vector<vector<int>> g(26,vector<int>(100005));
//初始化vec里面套了n个vec
//lower_bound(begin,end,num) 有序数列中返回第一个>=num的数字的地址
//upper_bound( begin,end,num) 返回第一个>num的数字的地址
const int maxn=305;
double dp[maxn][maxn][maxn];
int a[4]={0};
int n;
double dfs(int x,int y,int z){
    if(dp[x][y][z]>0) return dp[x][y][z];
    if(!x&&!y&&!z) return 0;
    int s=x+y+z;
    double ans=1.0*n/s;
    if(x) ans+=1.0*dfs(x-1,y,z)*x/s;
    if(y) ans+=1.0*dfs(x+1,y-1,z)*y/s;
    if(z) ans+=1.0*dfs(x,y+1,z-1)*z/s;
//    cout<<ans<<endl;
    return dp[x][y][z]=ans;
}
int main(){
    cin>>n;
    //memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        a[x]++;
    }
    double ans= dfs(a[1], a[2], a[3]);
    printf("%.10f\n",ans) ;
    return 0;
}
