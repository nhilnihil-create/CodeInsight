#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define cans cout << ans << endl
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
typedef long long ll;


int main(){
    int n;
    cin >> n;
    int now = 0;
    rep(i,n){
        int a;
        cin >> a;
        now = __gcd(a,now);
    }
    cout << now << endl;
    return 0;
}