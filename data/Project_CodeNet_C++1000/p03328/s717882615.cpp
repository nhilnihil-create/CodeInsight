#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    double a,b;
    cin >> a >> b;
    double c=b-a;
    cout << (c+1)*c/2-b << endl;
}
