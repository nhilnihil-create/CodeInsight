#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K,r;
    long ans = 0;
    cin >> N >> K;

    for(int a=K+1;a<=N;a++){
        r = N % a;
        ans += (N/a)*(a-K)+max(0,r-K+1);
        if (K==0){
            ans -= 1;
        }
        //cout << a << " " << ans << endl;
    }
    cout << ans << endl;
}