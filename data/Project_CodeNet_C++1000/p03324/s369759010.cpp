#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n,d;cin >> d >> n;
    int ans=1;
    
    for(int i = 0; i < d; i++) {
        ans *= 100;
    }

    if(n!=100) cout << ans*n << endl;
    else cout << ans*101 << endl;

    return 0;
}