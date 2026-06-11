#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    char s[51] = "";
    cin >> n >> k;
    cin >> s;
    s[k-1] = tolower(s[k-1]);
    cout << s;
    return 0;
}