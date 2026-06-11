#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;
const ll inf = 1e10;
int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    if((a < c && c < b) || (b < c && c < a))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
