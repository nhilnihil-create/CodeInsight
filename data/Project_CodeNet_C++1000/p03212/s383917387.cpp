#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TEST ll t;cin>>t;while(t--)
ll sizes[100001];
ll arr[100001];

bool ok=true;
ll A[100001];
pll B[100001];

ll root(ll i){
    while(i!=arr[i]) i=arr[i];
    return(i);
}
void Union(ll i,ll j){
    ll root_i=root(i),root_j=root(j);
    if(root_i==root_j) return;
    if(sizes[root_i]>sizes[root_j]) swap(root_i,root_j);
    sizes[root_j]+=sizes[root_i];
    arr[root_i]=arr[root_j];
    return;
}
bool prime[10000000];
vector<ll> v;
void era(){
    memset(prime,true,sizeof prime);
    for(int p=2;p*p<=10000000;p++){
        if(prime[p]){
            if(p%5==1) v.push_back(p);
            for(int q=p*p;q<=10000000;q+=p){
                prime[q]=false;
            }
        }
    }
    return;
}


ll dif(string s,string p){
    ll a=(s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
    ll b=(p[0]-'0')*100+(p[1]-'0')*10+(p[2]-'0');
    return(abs(a-b));
}
bool is357(ll i){
    bool a=false,b=false,c=false;
    while(i){
        if(i%10==3) a=true;
        else if(i%10==5) b=true;
        else if(i%10==7) c=true;
        else return(false);
        i/=10;
    }
    return(a&b&c);
}
int main(){
    IO
    ll N,ans=0;
    ll power[11];
    power[0]=1;
    for(int i=1;i<=10;i++) power[i]=power[i-1]*10;
    cin>>N;
    //N=999999999;
    queue<ll> q;
    int dp[11];
    memset(dp,0,sizeof dp);
    dp[0]=0;dp[1]=0;dp[2]=0;dp[3]=6;dp[4]=36;dp[5]=150;dp[6]=540;dp[7]=1806,dp[8]=5796,dp[9]=18150;
    //for(ll i=100000000;i<=999999999;i++) if(is357(i)) cout<<i<<endl;
    //cout<<dp[9];
    ll p=log10(N);

    for(ll i=0;i<=p+1;i++) ans+=dp[i];
    if(N%2==0) N++;
    else N+=2;
    for(ll i=N;i<=power[p+1]-3;i+=2) if(is357(i)) ans--;
    cout<<ans;
    return(0);
}
