#include <iostream>
using namespace std;
void ABC120(void);
void ABC121(void);
void ABC122(void);
void ABC123(void);
void ABC124(void);
void ABC125(void);
void ABC126(void);
void ABC127(void);
void ABC128(void);
void ABC129(void);

int main(void){
    ABC124();
}

void ABC124(){
    int a,b,sum=0;
    cin>>a>>b;
    if(a>b){
        sum=a;
        --a;
    }else{
        sum=b;
        --b;
    }
    if(a>b)sum+=a;
    else sum+=b;
    cout<<sum<<endl;
}