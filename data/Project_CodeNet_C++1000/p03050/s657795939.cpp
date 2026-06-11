#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(){
    long long N;
    cin >> N;
    long long ans = 0;
    for(long long i = 1; i * i < N; i++){
        if((N - i) % i == 0 && N % ((N - i) / i) != 0) ans += (N - i) / i;
    }
    cout << ans << endl;
}