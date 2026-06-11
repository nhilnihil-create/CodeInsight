#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int charge1, charge2, charge3;
    charge1=X*A+Y*B;
    charge2=max(X,Y)*2*C;
    int m=0;
    if(X>=Y){
        m=A;
    }else{
        m=B;
    }
    charge3=(max(X,Y)-min(X,Y))*(m) + min(X,Y)*2*(C);
    cout << min(charge1,min(charge2,charge3)) << endl;
    
    return 0;
}
