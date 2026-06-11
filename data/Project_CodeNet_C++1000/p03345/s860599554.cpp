#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll A,B,C,K;
    cin >> A >> B >> C >> K;
    if (K % 2 == 0) cout << A - B << endl;
    else cout << B - A << endl;
}

