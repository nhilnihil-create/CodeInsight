#include <iostream>
#include<math.h>
#include <limits>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i =0; i < (int)(n); i++)
int A[11111];
int tensuu[11111];
int main() {
    int a,b,c,d;
    cin >> a>>b>>c>>d;
    
    int ab, bc, ca;
    ab = abs(a - b);
    bc = abs(b - c);
    ca = abs(c - a);

    if ((ab <= d && bc <= d) || ca <= d)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}