#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int numb(int n, int k){
    int cntr = 0;
    while(n < k){
        cntr ++;
        n *= 2;
    }
    return cntr;
}
int main(){
    Hello
    double n, k;
    cin >> n >> k;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        double toPow = numb(i, k);
        ans += (1/n) * (pow(0.5, toPow));
    }
    cout << fixed << setprecision(9) << ans;
    return 0;
}
