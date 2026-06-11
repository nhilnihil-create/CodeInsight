#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
int n,a[200005],mi,len;vector<pii> v;
void add(int x,int c){
    len+=c;
    if(!v.empty()&&v.back().fi==x) v.back().se+=c;
    else v.pb(mpr(x,c));
}
void clear(){if(!v.empty()&&v.back().se==0) v.pop_back();}
bool check(int x){
    v.clear();len=0;
    rep(i,1,n){
        int c=a[i];
        if(a[i]>len) add(0,c-len);
        else {
            while(len-v.back().se>=c&&v.size()>0) len-=v.back().se,v.pop_back();
            v.back().se=c-(len-v.back().se);len=c;
            while(v.size()>0&&v.back().fi==x-1) len-=v.back().se,v.pop_back();
            if(v.empty()) return 0;
            v.back().se--;
            int w=v.back().fi+1;
            clear();
            add(w,1);len--;
            add(0,c-len);
            clear();

            //rap(i,0,v.size()) printf("%d %d\n",v[i].fi,v[i].se);
            //putchar('\n');
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",a+i);
    int l=1,r=n;
    //check(2);
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}