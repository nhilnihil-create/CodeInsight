#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
        result += vec.at(i) - 1;
    }
    
    cout << result << endl;
}
