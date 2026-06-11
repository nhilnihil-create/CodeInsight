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
    ABC80();
}

void ABC80(void){
    int n,a,b;
    cin>>n>>a>>b;
    if(n*a<b)cout<<n*a<<endl;
    else cout<<b<<endl;
}