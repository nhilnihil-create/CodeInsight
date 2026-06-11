#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//O[1]

int main() {
    ll N, K;
    cin >> N >> K;
    ll num = N/K;
    ll rem = N%K;
    
    ll count = 0;
    count += pow(num, 3);

    if (K % 2 == 0) {
        if (rem >= K/2) num ++;
        count += pow(num, 3);
    }

    cout << count << endl;
    return 0;
}