#include <iostream>
using namespace std;
void ABC90(void);
void ABC91(void);
void ABC92(void);
void ABC93(void);
void ABC94(void);
void ABC95(void);
void ABC96(void);
void ABC97(void);
void ABC98(void);
void ABC99(void);

int main(void){
    ABC98();
}

void ABC98(){
    int a,b,n[3],i,max;
    cin>>a>>b;
    n[0]=a+b;
    n[1]=a-b;
    n[2]=a*b;
    max=n[0];
    for(i=1;i<=2;++i){
        if(n[i]>max)max=n[i];
    }
    cout<<max;
}