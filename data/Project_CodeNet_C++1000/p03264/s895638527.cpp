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
    ABC108();
}

void ABC108(){
    int k;
    cin>>k;
    if(k%2==0)cout<<k*k/4<<endl;
    else cout<<(k+1)*(k-1)/4<<endl;
}