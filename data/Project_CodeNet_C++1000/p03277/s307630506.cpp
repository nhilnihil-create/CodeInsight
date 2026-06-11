#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a[ohara],b[ohara],c[ohara],d,tmp,tmpp,m,h,w,x,y,pos,k,bit[ohara];
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz");
bool fl;
struct edge{int to,cost;};
map<ll,ll> ac;

//-------------------------↓↓↓↓↓↓------------------------

ll summ(ll i){
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(ll i,ll x){
  while(i<=n){
    bit[i]+=x;
    i+=i&-i;
  }
}

bool check(ll res){
    ll sum[n+2]={};
    cnt=0;
    rep(i,n){
        if(a[i]<res)sum[i+1]=-1;
        else sum[i+1]=1;
    }
    sum[0]=n;
    rrep(i,0,n)sum[i+1]+=sum[i];
    rep(i,n+1)b[i]=sum[i];
    sort(b,b+n+1);
    tmpp=1;
    rep(i,n+1){
        ac[b[i]]=tmpp;
        if(b[i]!=b[i+1])tmpp++;
    }
    rep(i,n+1){
        sum[i]=ac[sum[i]];
    }
    fill(bit,bit+ohara,0LL);
    add(sum[0],1LL);
    rrep(i,1,n+1){
        cnt+=summ(sum[i]);
        add(sum[i],1LL);
    }
    pos=((n)*(n+1)/2)/2;
    if(((n)*(n+1)/2)%2==1)pos++;
    if(cnt>=pos)return true;
    else return false;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)cin>>a[i],c[i]=a[i];
    ll le=0,ri=n-1,mid;
    sort(c,c+n);
    while(ri-le>1){
        mid=(le+ri)/2;
        if(check(c[mid])){
            le=mid;
        }
        else{
            ri=mid;
        }
    }
    if(n==1)Cout(a[0]);
    else{
    rrrep(i,min(ri+10,n-1),max(le-10,0LL)){
        tmp=c[i];
        if(check(tmp)){
            Cout(tmp);
            return 0;
        }
    }
    }
    return 0;
}
