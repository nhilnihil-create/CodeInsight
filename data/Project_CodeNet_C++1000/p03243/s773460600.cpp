#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    if(n%111==0)cout << n <<endl;
    else cout << (1+n/111)*111 <<endl;
}