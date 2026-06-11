#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using P=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define endl '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int a, b, ans;
int main(){
    cin >> a >> b;
    rep(n, a, b+1){
        int t = n, rev = 0;
        rep(e, 0, 5){
            int tmp = t%10;
            rev += tmp * pow(10, 4-e);
            t /= 10;
        }
        if(n == rev) ans++;
    }
    cout << ans << endl;
    return 0;
}
