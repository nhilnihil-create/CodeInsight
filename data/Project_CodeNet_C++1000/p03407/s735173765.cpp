#include <iostream>
using namespace std;
int s,x,z,a;
int main(){
    cin>>x>>a>>z;
    s=a+x;
    if((a<=500)&&(a>=1)&&(x>=1)&&(x<=500)){
        if(s>=z){
            cout<<"Yes";
        } else {
            cout << "No";

        }
    }
    else{
        cout<<"you can't buy";
    }

    return 0;
}
