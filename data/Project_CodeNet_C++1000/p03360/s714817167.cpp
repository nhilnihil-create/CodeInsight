#include <bits/stdc++.h>
#include <math.h>
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
    ABC96();
}

void ABC96(){
    int a,b,c,k,ma,m,i;
    cin>>a>>b>>c>>k;
    ma=max(max(a,b),c);
    m=ma;
    for(i=0;i<k;i++){
        m*=2;
    }
    cout<<a+b+c-ma+m<<endl;
}