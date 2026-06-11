#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        int sum = 0;
        int num = i;
        while(1){
            sum+=num%10;
            num/=10;
            if(num==0 || sum > b) break;
           
        }
        if(sum >= a && sum <= b)ans+=i;
    }
    cout << ans << endl;
    return 0;
}