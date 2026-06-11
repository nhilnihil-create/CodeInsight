#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    int A = a*n;
    if(A > b) cout << b << endl;
    else cout << A << endl;
    return 0;
}