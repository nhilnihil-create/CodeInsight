#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    int n, a, b;    cin >> n >> a >> b;
    cout << min(a,b) << " " << max(a+b-n,0) << endl;
    return 0;
}