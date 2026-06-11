#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    double a[n];
    double ave = 0;
    REP(i,n){
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    int ans = 0;
    double mn = INF;
    REP(i,n){
        if(abs(a[i] - ave) < mn){
            ans = i;
            mn = abs(a[i] - ave);
        }
    }
    cout << ans << endl;
    return 0;
}