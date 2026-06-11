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
    int n;
    cin >> n;
    int ans = 0;
    int test_num = 1;
    int cnt = 0;
    while(1) {
        if ( cnt == n ) break;
        test_num *= 3;
        ++cnt;
    }
    int even = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if ( a % 2 == 0 ) ++even;
    }
    cnt = 0;
    int allodd = 1;
    while(1) {
        if ( cnt == even ) break;
        allodd *= 2;
        ++cnt;
    }
    cout << test_num - allodd << endl;
    return 0;
}
