#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;

int main()
{
    int a,b;
    cin >> a;
    b = a%100;
    a -=b;
    a /= 100;

    string ans;
    bool yymm=true;
    bool mmyy=true;
    if(b==0 || b>12) yymm=false;
    if(a==0 || a>12) mmyy=false;
    if(yymm&&mmyy) ans="AMBIGUOUS";
    else if(yymm) ans="YYMM";
    else if(mmyy) ans="MMYY";
    else ans="NA";

    cout << ans << endl;
    return 0;
}