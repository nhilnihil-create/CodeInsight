#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int a = min(X,Y),s = 0,c = 2*C;
    if(A+B >= c) s += c*a;
    else s += (A+B)*a;
    X -= a;Y -= a;
    if(A >= c)s += c*X;
    else s += A*X;
    if(B >= c)s += c*Y;
    else s += B*Y;
    cout << s << endl;
}