#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int a,b,c,k;
    cin >> a >> b >> c >> k;
    int j = pow(2,k);
    int x = max(max(a,b),c);
    cout << a+b+c-x+x*j << endl;
}