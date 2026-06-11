#include <iostream>
using namespace std;
int main(void){
    int D,N;
    cin >> D >> N;
    long long ans;
    if(D == 0){
        ans = N;
        if(N == 100){
            ans ++;
        }
    }
    if(D == 1){
        ans = 100 * N;
        if(N == 100){
            ans += 100;
        }
    }
    if(D == 2){
        ans = 10000 * N;
        if(N == 100){
            ans += 10000;
        }
    }
    cout << ans << endl;
}
