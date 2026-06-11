#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    char s[100];
    cin >> n >> k;
    cin >> s;
    s[k-1] += 32;
    printf("%s\n", s);
    
    return 0;
}