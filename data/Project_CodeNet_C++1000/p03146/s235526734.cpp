#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;

    vector<int> a(1,s);
    for (int i = 1; i <= 1000000; i++) {
        if (a[i-1]%2 == 0)
            a.push_back(a[i-1]/2);
        else
            a.push_back(3*a[i-1]+1);
        
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                cout << i+1 << endl;
                return 0;
            }
        }
    }
}