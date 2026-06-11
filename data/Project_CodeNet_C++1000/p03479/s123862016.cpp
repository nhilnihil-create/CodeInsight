#include<bits/stdc++.h>
using namespace std;

int main(){
    long long X=0,Y=0;
    int i=0;
    cin >> X >> Y;
    while(true){
        if(X>Y)break;
        i++;
        X *= 2;
    }
    cout << i << endl;
    return 0;
}