#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    long long N, P;
    cin >> N >> P;
    long long answer = 1;
    // P = ans^N * buf
    long long ans = pow(P, (double)1/N) + 1;
    while(true){
        long long a = pow(ans, N);
        if(P % a == 0){
            answer = ans;
            break;
        }
        ans--;
    }

    cout << answer << endl;
    return 0;
}
