#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)


int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int tmp;
    if(X > Y){
        tmp = Y*C*2 + (X-Y)*A;
    }else{
        tmp = X*C*2 + (Y-X)*B;
    }
    cout << min(min(A*X + B*Y, max(X,Y)*C*2),tmp) << endl;
    //cout <<  (flag ? "Yes" : "No") << endl;
}
