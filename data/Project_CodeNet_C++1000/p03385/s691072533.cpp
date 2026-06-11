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
    ABC93();
}

void ABC93(){
    string a;
    int i,k=0,l=0,m=0;
    cin>>a;
    for(i=0;i<=2;++i){
        if(a[i]=='a')k++;
        if(a[i]=='b')l++;
        if(a[i]=='c')m++;
    }
    if(k==1&&l==1&&m==1)cout<<"Yes";
    else cout<<"No";
}