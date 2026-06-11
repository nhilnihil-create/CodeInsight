#include <iostream>
using namespace std;
int main(void){
    int a,b,k;
    cin>>a>>b>>k;
    int tmp;
    for (int i=0;i<k;i++){
        tmp=a/2+a%2;
        a-=tmp;
        b+=a;
        tmp=a;a=b;b=tmp;
    }
    if (k%2){
        tmp=a;a=b;b=tmp;
    }
    cout<<a<<' '<<b;
};
