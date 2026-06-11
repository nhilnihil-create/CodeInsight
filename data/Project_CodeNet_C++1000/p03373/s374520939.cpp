#include<bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    if(A+B<=2*C) {
        cout<<A*X+B*Y<<endl;
        return 0;
    }
    else if(A+B>2*C&&X>=Y){
        if(A*(X-Y)<=2*C*(X-Y)) {
            cout<<2*C*Y+A*(X-Y)<<endl;
            return 0;
        }
        else{
             cout<<2*C*X<<endl;
             return 0;
        }
    }
    else {
        if(B*(Y-X)<=2*C*(Y-X)){
            cout<<2*C*X+B*(Y-X)<<endl;
            return 0;
        }
        else{
            cout<<2*C*Y<<endl;
            return 0;
        }
    }
}