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
    int n, k;
    cin >> n >> k;
    int max_num = 0;
    if ( n % 2 == 1 ) max_num = ( n + 1 ) / 2;
    else              max_num = n / 2; 
    if ( max_num >= k ) cout << "YES" << endl;
    else                cout << "NO" << endl;
    return 0;
}
