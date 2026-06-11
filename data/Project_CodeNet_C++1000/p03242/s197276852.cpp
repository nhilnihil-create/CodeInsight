#include <iostream>
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
    string s;
    cin>>s;
    for(int i=0;i<=2;++i){
        if(s[i]=='1')s[i]='9';
        else if(s[i]=='9')s[i]='1';
    }
    cout<<s<<endl;
}