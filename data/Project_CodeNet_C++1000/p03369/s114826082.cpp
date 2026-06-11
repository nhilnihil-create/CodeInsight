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
    ABC95();
}

void ABC95(){
    int sum=700;
    string a;
    cin>>a;
    for(int i=0;i<=2;++i){
        if(a[i]=='o')sum+=100;
    }
    cout<<sum;
}