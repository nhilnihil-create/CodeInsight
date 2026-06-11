#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    int  T,X;
    cin >> T >> X;
    cout << ((X % T == 0)? (T+X) : (X-T));
}