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
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main() {
    int n[4];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    sort(n, n+4);
    do {
        if ( n[0] == 1 && n[1] == 9 && n[2] == 7 && n[3] == 4 ) {
            cout << "YES" << endl;
            return 0;
        }
    } while( next_permutation(n, n+4) );
    cout << "NO" << endl;
    return 0;
}
