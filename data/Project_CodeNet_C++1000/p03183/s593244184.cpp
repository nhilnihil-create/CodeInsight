#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define gcd __gcd
#define in(a) scanf("%d",&a)
#define in2(a,b) scanf("%d%d",&a,&b)
#define in3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define read(v,i,n) for(i=0;i<n;i++)in(v[i])
#define twod(mat,i,j,n,m) rep(i,n){rep(j,m)in(mat[i][j]);}
#define sc(ch) scanf("%c",&ch)
#define sstr(str) scanf("%s",str)
#define pr(n) printf("%d ",n)
#define out(n) printf("%d\n",n)
#define inl(a) cin >> a
#define prl(a) cout << a << " "
#define outl(a) cout << a << endl
#define yes printf("YES\n")
#define no printf("NO\n")
#define lin printf("\n")
#define dbg(v,i,n) for(i=0;i<n;i++)pr(v[i]); lin
#define ck printf("continue\n")
#define all(vec) vec.begin(),vec.end()
#define asc(vec) sort(vec.begin(),vec.end())
#define lower(v,k) lower_bound(v.begin(),v.end(),k)-v.begin()
#define upper(v,k) upper_bound(v.begin(),v.end(),k)-v.begin()
#define tf(mytuple) get<0>(mytuple)
#define ts(mytuple) get<1>(mytuple)
#define tt(mytuple) get<2>(mytuple)
#define tddd tuple<double,double,double>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vvi vector<vector<int> >
#define viii vector<pair<pair<int,int>,int > >
#define vvii vector<vector<pair<int,int> > >
#define lp(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) for(i=0;i<n;i++)
#define N 10005
typedef long long int ll;
ll dp[N];
bool cmp(pair<ii,int> A,pair<ii,int> B)
{
    if(min(A.F.S,B.F.S-A.F.F)!=min(B.F.S,A.F.S-B.F.F))
        return (min(A.F.S,B.F.S-A.F.F)>min(B.F.S,A.F.S-B.F.F));
    return false;
}
int main()
{
    int i,j,n,w,c,v;
    int C=0;
    in(n);
    viii ad(n);
    rep(i,n)
    {
        in3(w,c,v);
        C=max(C,c);
        ad[i]={{w,c},v};
    }
    sort(all(ad),cmp);
    ll x,ans=0;
    rep(i,n)
    {
        w=ad[i].F.F,c=ad[i].F.S,v=ad[i].S;
        x=0;
        rep(j,c+1)
            x=max(x,dp[j]);
        ans=max(ans,x+v);
        for(j=min(C,c+w);j>=w;j--)
            dp[j]=max(dp[j],v+dp[j-w]);
    }
    outl(ans);
}






