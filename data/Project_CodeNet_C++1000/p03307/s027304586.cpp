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
    ABC102();
}

void ABC102(){
    long int n;
    cin>>n;
    if(n%2==0)cout<<n<<endl;
    else cout<<n*2<<endl;
}