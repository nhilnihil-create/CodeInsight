#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    cout << (a == b && b == c ? "Yes" : "No");
    
    return 0;
}