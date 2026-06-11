#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int sum[n] = { 0 };
    int count = 0;
    for (auto i = 0; i < n; i++) {
        if(s[i] == 'E') count++;
        sum[i] += count;
    }

    int min = sum[n - 1];
    for (auto i = 1; i < n; i++) {
        int tmp = (sum[n - 1] - sum[i]) + (i - sum[i - 1]);
        if(tmp < min) min = tmp;
    }

    cout << min << endl;
    return 0;
}