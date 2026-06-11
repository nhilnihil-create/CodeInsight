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
    int a, b, c;
    cin >> a >> b >> c;
    if ( abs(b-a) > abs(c-a) && ( b > a && c > a || b < a && c < a ) ) {
        cout << "Yes" << endl;
    } 
    else {
        cout << "No" << endl;
    }
    return 0;
}
