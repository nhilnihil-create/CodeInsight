#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    int ret=0;
    int c=1<<29;
    rep(j,29){
        ret*=2;
        rep(i,n)if(a[i]>=c)a[i]-=c;
        rep(i,n)if(b[i]>=c)b[i]-=c;
        c>>=1;
        sort(a,a+n);
        ll cnt=0;
        rep(i,n){
            if(b[i]>=c){
                cnt+=lower_bound(a,a+n,2*c-b[i])-a;
                cnt+=n;
                cnt-=lower_bound(a,a+n,3*c-b[i])-a;
            }
            else {
                cnt+=lower_bound(a,a+n,2*c-b[i])-a;
                cnt-=lower_bound(a,a+n,c-b[i])-a;
            }
        }
        if(cnt&1)ret++;
    }
    cout<<ret<<endl;
    return 0;
}
