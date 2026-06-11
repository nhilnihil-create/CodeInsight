#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    string a, b, c; cin >> a >> b >> c;

    int ans = 0;
    rep(i, n){
        if(a[i] == b[i] && b[i] == c[i]){
            continue;
        }
        if(a[i] == b[i] || b[i] == c[i] || c[i] == a[i]){
            ans++;
        }
        else{
            ans += 2;
        }
    }

    cout << ans << endl;

    return 0;
}