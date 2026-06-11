#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(int)(n);i++)
typedef long long ll;
////////////////////////////////////////////////
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a+b>c+d) cout << "Left" << endl;
    else if (a + b == c + d) cout << "Balanced" << endl;
    else cout << "Right" << endl;
}