#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;cin >> N;
    int ans = 11451419;
    for(int i = 1;i<N;i++){
        int A = i;
        int B = N-i;
        int digitsum = 0;
        while(A > 0){
            digitsum += A%10;
            A /= 10;
        }
        while(B > 0){
            digitsum += B%10;
            B /= 10;
        }
        ans = min(ans,digitsum);
    }
 
    cout << ans << endl;
}