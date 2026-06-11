#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if ( b >= c ) ans = b + c;
    else if ( a + b >= c ) ans = b + c;
    else                   ans = b + ( a + b + 1 );
    cout << ans << endl;
    return 0;
}
