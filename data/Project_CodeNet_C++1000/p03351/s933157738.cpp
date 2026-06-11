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
    ABC97();
}

void ABC97(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((abs(a-b)<=d&&abs(b-c)<=d)||abs(a-c)<=d)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}