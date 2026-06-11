#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x = max({a, b, c});
    if(x%2 != (a+b+c)%2){
        x++;
    }
    int ans = (3*x - (a+b+c))/2;
    cout << ans << endl;

    return 0;
}   