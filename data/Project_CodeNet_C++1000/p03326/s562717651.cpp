#include<bits/stdc++.h>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N=1e5+5;
//ll a[N],sum[N];
struct node{
    ll a,b,c;
}p[N];
int n,m,i,j,k;
bool cmp(node x,node y){
    return x.a*i+x.b*j+x.c*k>y.a*i+y.b*j+y.c*k;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n>>m;
    ll ans=0;
    for(int i=1;i<=n;i++)   cin >>p[i].a>>p[i].b >>p[i].c;
    for( i=-1;i<=1;i+=2){// i,j,k分别代表绝对值里的符号趋向
        for( j=-1;j<=1;j+=2){
            for( k=-1;k<=1;k+=2){
                sort(p+1,p+1+n,cmp);
                ll t[4]={0};
                for(int te=1;te<=m;te++)    t[1]+=p[te].a,t[2]+=p[te].b,t[3]+=p[te].c;
                ans=max(ans,t[1]*i+t[2]*j+t[3]*k);
            }
        }
    }
    cout << ans << endl;
 
    return 0;
}