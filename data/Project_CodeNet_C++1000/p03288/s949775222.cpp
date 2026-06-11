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
    ABC104();
}

void ABC104(void){
    int r;
    cin>>r;
    if(r<1200)cout<<"ABC"<<endl;
    else if(r<2800)cout<<"ARC"<<endl;
    else cout<<"AGC"<<endl;
}
