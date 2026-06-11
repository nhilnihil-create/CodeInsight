#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int max_num = 0;
    max_num = min(a, b);
    int min_num = 0;
    if ( a + b < n ) min_num = 0;
    else             min_num = ( a + b - n );
    cout << max_num << " " << min_num << endl;
    return 0;
}
