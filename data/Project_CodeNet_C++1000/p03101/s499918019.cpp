#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
    int v,s;
    cin >> v >> s;
    int h,w;
    cin >> h >> w;
    cout <<  s*v - ((s * h + v * w) - h * w);
}