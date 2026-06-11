#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    long double n,m,d;
    cin >> n >> m >> d;
    long double ans;
    if(d==0){
        ans=(m-1)/n;
    }
    else{
        ans=2*(m-1)*(n-d)/(n*n);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}