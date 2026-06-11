#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i<b; i++)
typedef long long ll;
int main() {
    
    long long int ans,k,a,b;
    cin >> k >> a >> b;
    
    if(b-a >= 2) {
        long long int cnt = (k-(a-1))/2;
        ans = a;
        ans += cnt * (abs(b-a));
        ans += (k-(a-1))%2;
        cout << ans << endl;
    } else {
        cout << k+1 << endl;
    }
    return 0;
}
