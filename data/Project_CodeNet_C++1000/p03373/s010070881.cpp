#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int A, B, C;
    int X, Y;
    long long min = 5000000000;
    cin >> A >> B >> C >> X >> Y;
    int cmax;
    long long t;
    int a, b, c;
    if(X <= Y) cmax = Y;
    else cmax = X;
    for(c = 0; c <= 2*cmax; c++){
        a = X - (int)(c/2);
        b = Y - (int)(c/2);
        if(a < 0) a = 0;
        if(b < 0) b = 0;
        t = A*a + B*b + C*c;
        if(min > t) min = t;
    }

    cout << min << endl;
    return 0;
}