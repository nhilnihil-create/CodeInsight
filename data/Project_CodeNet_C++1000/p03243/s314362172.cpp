#include <bits/stdc++.h>
#include <math.h>
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
    ABC111();
}

void ABC111(){
    int i,n,a,b,c;
    cin>>n;
    for(i=n;i<=999;i++){
        a=i%10;
        b=(i/10)%10;
        c=i/100;
        if(a==b&&b==c)break;
    }
    cout<<c<<b<<a<<endl;
}