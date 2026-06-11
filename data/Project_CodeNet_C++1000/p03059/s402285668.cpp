#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a,b,t,s=0,k;
    cin>>a>>b>>t;
    k=a;
    while(k<=t){
        s+=b;
        k+=a;
    }
    cout<<s<<endl;
    return 0;
}