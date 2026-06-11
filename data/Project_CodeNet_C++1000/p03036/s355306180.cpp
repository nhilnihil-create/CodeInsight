#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;

int main(){
    int r,d,x;
    cin >> r >> d >> x;
    for(int i = 1; i <= 10;i++){
        x = r*x - d;
        cout << x << endl;
    }
}