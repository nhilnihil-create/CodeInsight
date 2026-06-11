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
    ABC120();
}

void ABC120(){
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=a*c) cout<<c<<endl;
    else cout<<b/a<<endl;
}