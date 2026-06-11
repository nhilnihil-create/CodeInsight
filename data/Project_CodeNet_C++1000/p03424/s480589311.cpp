#include <bits/stdc++.h>
using namespace std;

bool freq[26];
int nr, n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        if(freq[c - 'A'] == 0) {
            nr++;
            freq[c - 'A'] = 1;
        }
    }
    if(nr == 3) {
        cout << "Three";
    } else {
        cout << "Four";
    }
    return 0;
}
