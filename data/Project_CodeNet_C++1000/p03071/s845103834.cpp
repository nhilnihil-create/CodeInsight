#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;

int main() {
    int a,b;
    cin >> a >> b;
    cout << max(a,b)+max(max(a,b)-1,min(a,b)) << endl;
}