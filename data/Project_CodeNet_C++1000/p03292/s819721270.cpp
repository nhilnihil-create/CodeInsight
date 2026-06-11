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
    ABC103();
}

void ABC103(){
    int a,b,c,min,max;
    cin>>a>>b>>c;
    min=a;
    max=a;
    if(b<min)min=b;
    if(c<min)min=c;
    if(b>max)max=b;
    if(c>max)max=c;
    cout<<max-min<<endl;
}