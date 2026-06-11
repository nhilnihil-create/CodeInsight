#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
// #include <cmath>
// #include <math.h>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int x = 0;
    int y = 0;
    int z = 0;

    if (A > 2*C){
        // Xは全てCで
        z += 2*X;
        Y -= X;
        X -= X;
    }
    
    if (X < 0) X=0;
    if (Y < 0) Y=0;

    // cout << X << " " << Y << " " << z <<endl;

    if (B > 2*C){
        // Yは全てCで 
        z += 2*Y;
        X -= Y;
        Y -= Y;
    }

    // cout << X << " " << Y << " " << z <<endl;

    if (X < 0) X=0;
    if (Y < 0) Y=0;

    if (A + B > 2*C){
        // なるべくCで
        int n = min(X, Y);
        z += 2*n;
        X -= n;
        Y -= n;
    }

    // 残りは素直に
    x += X;
    y += Y;

    cout << A*x + B*y + C*z << endl;

}