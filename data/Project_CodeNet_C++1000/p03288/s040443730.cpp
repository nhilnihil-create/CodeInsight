#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int r; cin >> r;
    string abc="ABC",agc="AGC",arc="ARC";
    string ans;
    if(r<1200) ans = abc;
    else if(r<2800) ans = arc;
    else ans = agc;
    cout << ans;
}
