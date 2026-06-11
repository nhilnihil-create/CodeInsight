#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int same = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                same = 1;
            }
        }
    }
    
    int flag = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i][arr[i].size() - 1] != arr[i+1][0]) {
            flag = 1;
        }
    }

    if (flag == 0 && same == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
