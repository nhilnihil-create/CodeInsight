#include <iostream>
using namespace std;
void ABC70(void);
void ABC71(void);
void ABC72(void);
void ABC73(void);
void ABC75(void);
void ABC77(void);
void ABC78(void);
void ABC79(void);

int main(void){
    ABC75();
}

void ABC75(void){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b)cout<<c<<endl;
    if(a==c)cout<<b<<endl;
    if(b==c)cout<<a<<endl;
}