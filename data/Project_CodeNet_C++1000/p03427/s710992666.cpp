#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    ll n;cin >> n;
    ll t=n,m=1;
    while(t>=10){
        t /= 10;
        m++;
    }
    int nine=0;
    for(int i = 0; i < m; i++) {
        if(n%10==9){
            nine++;
        }
        if(i!=m-1) n /= 10;
    }

    if(nine==m) cout << m*9 << endl;
    else if(nine==m-1 && n != 9) cout << t+(m-1)*9 << endl;
    else cout << (m-1)*9+t-1 << endl;

    return 0;
}