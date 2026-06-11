#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int q;
    cin >> q;
    rep(zz,q){
        ll a,b;
        cin >> a >> b;
        if(a>b)swap(a,b);
        ll res = 0;
        res += 2*(a-1);
        ll p = a*b;
        if(b>a+1){
            res++;
        }
        ll lo = a+1;
        ll up = b-2;
        if(up>=lo){
            ll s = 0;
            ll t = 1e9;
            while(t-s>1){
                ll mid = (s+t)/2;
                if(mid*mid<p){
                    s = mid;
                }else{
                    t = mid;
                }
            }
            ll q = s;
            ll tmp = 0;
            //cerr << p << " " << q*q << endl;
            if(lo<=q&&q<=up){
                tmp = 2*min(q-lo,up-q)+1;
                if(q*(q+1)<p){
                    tmp = max(tmp,2*min(q-lo+1,up-q));
                }
            }
            res += tmp;
        }
        cout << res << endl;
    }

    return 0;
}