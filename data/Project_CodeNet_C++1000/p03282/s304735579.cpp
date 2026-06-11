#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    string S, ans;
    long long int K;
    cin >> S >> K;

    if (S[0] != '1') {
        ans = S[0];
    }
    else{
        for (int i = 0; i < K; i++) {
            if (S[i] == '1') {
                if (i == K - 1) {
                    ans = '1';
                }
                else {
                    continue;
                }
            }
            else {
                ans = S[i];
                break;
            }            
        }
    }

    cout << ans;

    return 0;

}

