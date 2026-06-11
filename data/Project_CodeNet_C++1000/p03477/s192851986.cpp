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
    ABC83();
}

void ABC83(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a+b)>(c+d))cout<<"Left"<<endl;
    else if(a+b==c+d)cout<<"Balanced"<<endl;
    else cout<<"Right"<<endl;
}