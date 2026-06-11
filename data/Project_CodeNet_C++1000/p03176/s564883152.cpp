#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000007
#define MOD2 998244353
#define MOD3 1000000009
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("in.in");ofstream coutt("out.out");
int poww(const int &a,int b,const int &m=MOD){if(b==0)return 1;int x=poww(a,b/2,m);x=x*x%m;if(b&1)x=x*a%m;return x;}
int ceil(const int &a,const int &b){return (a+b-1)/b;}
////Read:
//Check corner cases, n==1;
//
////Some function:
//__builtin_popcountll(), 

int n;
int h[200005],a[200005];
int dp[200005];
int tree[4*200005];

void updatee(int s,int e,int idx,int SE,int val){
    if(s>SE || e<SE)return;
    if(s==e){
        tree[idx]=val;
        return;
    }
    int mid=(s+e)/2;
    updatee(s,mid,idx*2+1,SE,val);
    updatee(mid+1,e,idx*2+2,SE,val);
    tree[idx]=max(tree[idx*2+1],tree[idx*2+2]);
}

int gett(int s,int e,int idx,int S,int E){
    if(s>E || e<S)return 0;
    if(s>=S && e<=E)return tree[idx];
    int mid=(s+e)/2;
    return max(gett(s,mid,idx*2+1,S,E),gett(mid+1,e,idx*2+2,S,E));
}

signed main(){
    FASTER;
    cin>>n;
    int mxH=0;
    for(int i=0;i<n;i++)cin>>h[i],mxH=max(mxH,h[i]);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        dp[h[i]]=gett(0,mxH-1,0,0,h[i]-1)+a[i];
        updatee(0,mxH-1,0,h[i],dp[h[i]]);
        ans=max(ans,dp[h[i]]);
    }
    cout<<ans;
    
}
