#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int tot(int a, int b) {
    int t = 0;
    while(a != 0 || b != 0) {
        t += (a%10+b%10);
        a /= 10;
        b /= 10;
    }
    return t;
}




int main(){
    int n;
    cin >> n;
    
    int ans = inf;
    for(int i = 1; i <= n-1; i++) {
        ans = min(ans, tot(i, n-i));
    }
    cout << ans << endl;

}