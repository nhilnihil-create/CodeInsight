/**
*    created: 12.05.2020 09:15:30
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int c = b - a;
    if(c%2==0) cout << "Alice" << endl;
    else cout << "Borys" << endl;
}