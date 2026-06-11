#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    if(s == "abc") {
        puts("Yes");
    } else {
        puts("No");
    }
    return 0;
}