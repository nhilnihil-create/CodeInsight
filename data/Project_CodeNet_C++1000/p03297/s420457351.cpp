#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9,MOD = 1e9+7,ohara = 1e6;
const ll LINF = 1e18;
using namespace std;

#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,t;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);
      
    cin>>t;
    rep(i,t){
        cin>>a>>b>>c>>d;
        if(a<b)Cout("No");
        else if(b>d)Cout("No");
        else{
            pos=b-__gcd(b,d)+a%__gcd(b,d);
            if(pos>c)Cout("No");
            else Cout("Yes");
        }
    }
    return 0;
}
