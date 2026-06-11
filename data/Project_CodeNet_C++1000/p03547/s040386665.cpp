#include <iostream>
using namespace std;
void ABC70(void);
void ABC71(void);
void ABC72(void);
void ABC73(void);
void ABC75(void);
void ABC77(void);
void ABC78(void);
void ABC79(void);

int main(void){
    ABC78();
}

void ABC78(void){
    char x,y;
    cin>>x>>y;
    if(x<y)cout<<'<'<<endl;
    else if(x>y)cout<<'>'<<endl;
    else cout<<'='<<endl;
}