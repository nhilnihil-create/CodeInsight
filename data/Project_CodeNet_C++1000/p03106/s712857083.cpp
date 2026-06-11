#include <bits/stdc++.h>
#include <math.h>
int n,m,i,j,k,count1=0,count2=0;
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
    int a,b;
    cin>>a>>b>>k;
    for(i=min(a,b);i>=0;i--){
        if(a%i==0&&b%i==0)count1++;
        if(count1==k)break;
    }
    cout<<i<<endl;
}