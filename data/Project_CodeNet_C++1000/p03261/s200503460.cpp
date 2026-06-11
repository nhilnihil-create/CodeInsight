#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    char prev = a[0][a[0].length()-1];
    for (int i=0; i<n; i++) {
        string s = a[i];
        for (int j=i+1; j<n; j++) {
            if (s == a[j]) {
                cout << "No\n";
                return 0;
            }
        }
    }
    for (int i=1; i<n; i++) {
        if (prev != a[i][0]) {
            cout << "No\n";
            return 0;
        }
        prev = a[i][a[i].length()-1];
    }
    cout << "Yes\n";
    return 0;
}