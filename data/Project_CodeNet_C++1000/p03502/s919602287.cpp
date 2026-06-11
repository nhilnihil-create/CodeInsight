#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    string str;
    long long num;
    long long sum = 0;

    cin >> num;
    str = to_string(num);
    for (int i = 0; i < str.size(); i++) {
        sum += str.at(i) - '0';
    }

    if(num % sum == 0) cout << "Yes";
    else cout << "No";
}
