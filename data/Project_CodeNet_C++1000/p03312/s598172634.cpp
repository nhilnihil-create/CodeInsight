#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    int n;
    cin >> n;
    vector<ll>a(n),s(n);
    rep(i,n){
        cin >> a[i];
        s[i] += a[i];
        if(i!=0)s[i] += s[i-1];
    }
    ll ans = 1LL<<60;
    for(int i=1;i<n-1;i++){
        vector<ll> p;
        ll tmp1,tmp2;
        ll x = s[i];
        ll tx = (x+1)/2;
        ll ind = lower_bound(s.begin(),s.end(),tx)-s.begin();
        ll pp,qq;
        if(ind==0){
            pp = s[0];
            qq = s[i]-s[0];
        }else{
            pp = s[ind-1];
            qq = s[i]-s[ind-1];
            if(abs(pp-qq)>abs(s[ind]-(s[i]-s[ind]))){
                pp = s[ind];
                qq = s[i]-s[ind];
            }
        }
        //cerr << pp << " " << qq << " ";
        p.PB(pp);p.PB(qq);
        ll y = s[n-1]-s[i];
        ll ty = s[i] +  (y+1)/2;
        ind = lower_bound(s.begin(),s.end(),ty)-s.begin();
        if(ind==i+1){
            pp = s[i+1]-s[i];
            qq = s[n-1]-s[i+1];
        }else{
            pp = s[ind-1]-s[i];
            qq = s[n-1]-s[ind-1];
            if(abs(pp-qq)>abs(s[ind]-s[i]-(s[n-1]-s[ind]))){
                pp = s[ind]-s[i];
                qq = s[n-1]-s[ind];
            }
        }

       // cerr << pp << " " << qq << endl;
        p.PB(pp);p.PB(qq);
        sort(p.begin(),p.end());
        ans = min(ans,p[3]-p[0]);
    }
    cout << ans << endl;
    return 0;
}