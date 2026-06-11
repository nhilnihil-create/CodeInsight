#include <iostream>
using namespace std;
void ABC80(void);
void ABC81(void);
void ABC83(void);
void ABC85(void);
void ABC86(void);
void ABC87(void);
void ABC88(void);
void ABC89(void);

int main(void){
    ABC86();
}

void ABC86(void){
    int a,b;
    cin>>a>>b;
    if((a*b)%2==1)cout<<"Odd"<<endl;
    else cout<<"Even"<<endl;
}