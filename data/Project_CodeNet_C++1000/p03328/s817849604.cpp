#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC90(void);
void ABC91(void);
void ABC92(void);
void ABC93(void);
void ABC94(void);
void ABC95(void);
void ABC96(void);
void ABC97(void);
void ABC98(void);
void ABC99(void);

int main(void){
    ABC99();
}

void ABC99(){
    int n,i,a,b,sum=0;
    cin>>a>>b;
    for(i=1;i<b-a;i++){
        sum+=i;
    }
    cout<<sum-a<<endl;
}