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
    int n, h, w;
    cin >> n >> h >> w;
    cout << ( n - h + 1 ) * ( n - w + 1 ) << endl;
    return 0;
}
