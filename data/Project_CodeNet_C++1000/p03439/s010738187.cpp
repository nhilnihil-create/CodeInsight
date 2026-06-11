#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

bool odd(string sl, string sr, int l, int r){
    if(sr==sl) return (r-l)%2 == 1;
    else return (r-l)%2 == 0;
}
void solve(int n){
    
    
    string vac = "Vacant";
    string sl, sr, str;
    int l=0, r=n/2;
    cout << l << endl;
    cin >> sl;
    if(sl==vac) return;
    cout << r << endl;
    cin >> sr;
    if(sr==vac) return;
    //[0, n/2), (n/2, n-1]
    if(!odd(sl, sr, l, r)){
        swap(sl, sr); l = r; r=n;
    }
    while(1<r-l){
        int mid = (l+r)/2;
        cout << mid << endl;
        cin >> str;
        if(str==vac) return;
        if(odd(sl, str, l, mid)){
            sr = str; r=mid;
        }else{
            sl = str; l = mid;
        }

    }

}
int main(){
    int n;
    while(cin >> n) solve(n);
}