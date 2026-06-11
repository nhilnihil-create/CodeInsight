#include <iostream>
using namespace std;
void ABC110(void);
void ABC111(void);
void ABC112(void);
void ABC113(void);
void ABC114(void);
void ABC115(void);
void ABC116(void);
void ABC117(void);
void ABC118(void);
void ABC119(void);

int main(void){
    ABC110();
}

void ABC110(){
    int a,b,c,max;
    cin>>a>>b>>c;
    max=a;
    if(b>=max)max=b;
    if(c>=max)max=c;
    if(a==max)cout<<a*10+b+c<<endl;
    else if(b==max)cout<<b*10+a+c<<endl;
    else if(c==max)cout<<c*10+a+b<<endl;
}