#include <iostream>
using namespace std;
void ABC100(void);
void ABC101(void);
void ABC102(void);
void ABC103(void);
void ABC104(void);
void ABC105(void);
void ABC106(void);
void ABC107(void);
void ABC108(void);
void ABC109(void);

int main(void){
    ABC101();
}

void ABC101(){
    string a;
    cin>>a;
    int i,sum=0;
    for(i=0;i<=3;++i){
        if(a[i]=='+')++sum;
        if(a[i]=='-')--sum;
    }
    cout<<sum;
}