#include <bits/stdc++.h>
using namespace std;

int n;
long long v[6], sol;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if(s[0] == 'M') {
            v[1]++;
        }
        if(s[0] == 'A') {
            v[2]++;
        }
        if(s[0] == 'R') {
            v[3]++;
        }
        if(s[0] == 'C') {
            v[4]++;
        }
        if(s[0] == 'H') {
            v[5]++;
        }
    }
    for(int i = 1; i <= 3; i++) {
        for(int j = i + 1; j <= 4; j++) {
            for(int k = j + 1; k <= 5; k++) {
                sol += v[i] * v[j] * v[k];
            }
        }
    }
    cout << sol;
    return 0;
}
