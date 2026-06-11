#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int a, b;
    cin >> a >> b;
    if(a*b % 2 == 0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    
    return 0;
}
