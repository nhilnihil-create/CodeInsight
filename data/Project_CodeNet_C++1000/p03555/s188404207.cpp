#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    char s1[5], s2[5];
    cin >> s1;
    cin >> s2;
    if (s1[0] == s2[2] && s1[1] == s2[1] && s1[2] == s2[0])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}