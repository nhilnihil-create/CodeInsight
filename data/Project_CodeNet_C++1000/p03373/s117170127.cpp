#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,X,Y,XY,bestsum;
    cin >> A >> B >> C >> X >> Y;
    bestsum=A*X+B*Y;

    for(XY=0;X>=0||Y>=0;XY++,X--,Y--){
        if(X<0)X=0;
        if(Y<0)Y=0;
        if(bestsum>A*X+B*Y+C*XY*2)bestsum=A*X+B*Y+C*XY*2;
    }

    cout << bestsum << endl;

    return 0;
}