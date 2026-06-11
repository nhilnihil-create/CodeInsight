#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())


ll gcd(ll a, ll b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(){
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3,x4,y3,y4;
    x3 = x2-(y2-y1);    y3 = y2+x2-x1;
    x4 = x1-(y2-y1);    y4 = y1+x2-x1;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}