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
    string S;
    cin >> S;
    long long int ans = 0;
    int key = S.size() - 1;

    for (int i = S.size() - 1; i >= 0; i--) {
        if (S[i] == 'B') {
            ans += key - i;
            key--;
        }
    }

    cout << ans;

    return 0;
}