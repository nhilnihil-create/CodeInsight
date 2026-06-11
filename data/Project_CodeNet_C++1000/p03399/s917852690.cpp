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
    ABC92();
}

void ABC92(){
    int a,b,c,d,sum=0;
    cin>>a>>b>>c>>d;
    if(a<b)sum+=a;
    else sum+=b;
    if(c<d)sum+=c;
    else sum+=d;
    cout<<sum;
}