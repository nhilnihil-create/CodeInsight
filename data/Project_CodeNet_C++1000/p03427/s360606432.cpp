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
    int max = 0, sum = 0;
    string S;

    cin >> S;

    for(int i = 1; i < S.size(); i++) {
        if(S[i] =='9')
        sum++;
    }

    if (sum == S.size() - 1) {
        max = S[0] -48 + 9 * (S.size() - 1);
    }
    else {
        max = S[0] -48 + 9 * (S.size() - 1) - 1;
    }

    cout << max;

}

