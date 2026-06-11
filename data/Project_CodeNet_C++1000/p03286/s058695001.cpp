#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int n; sc(n)
    string ans;
    if (n == 0) ans += '0';
    while (n != 0){
        if (n % 2 == 0) ans += '0';
        else ans += '1';
        if (n > 0) n = -n / 2;
        else {
            if (n % 2 == 0) n = -n / 2;
            else n = (-n + 1) / 2;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}