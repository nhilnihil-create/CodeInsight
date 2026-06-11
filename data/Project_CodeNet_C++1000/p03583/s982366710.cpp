#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(long long int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
int main() {
    ll N; cin >> N;
    req(h, 3500) {
        req(n, 3500) {
            ll w = N * h * n, x = 4 * h * n - N * n - N * h;
            if (x!=0 && w%x==0 && w/x>0) {
                cout << h << " " << n << " " << w / x << endl;
                return 0;
            }
        }
    }
}