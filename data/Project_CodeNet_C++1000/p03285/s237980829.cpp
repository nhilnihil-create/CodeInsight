#include <bits/stdc++.h>
#include <math.h>
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
    ABC105();
}

void ABC105(){
    int n,i,j,ans=0;
    cin>>n;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if(n==4*i+7*j)ans=1;
        }
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}