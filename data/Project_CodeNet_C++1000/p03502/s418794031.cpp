#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int main(){
    long long n;
    cin >> n;
    long long m = n;
    int sum = 0;
    while(true){
        sum += n % 10;
        n /= 10;
        if(n == 0) break;
    }
    if( m % sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
