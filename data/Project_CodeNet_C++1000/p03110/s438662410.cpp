#include <bits/stdc++.h>
#include <math.h>
int n,m,i,j,k,count1=0,count2=0;
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
    ABC119();
}

void ABC119(){
    cin>>n;
    double sum=0,x;
    string u;
    for(i=0;i<n;i++){
        cin>>x>>u;
        if(u=="JPY")sum+=x;
        else if(u=="BTC")sum+=380000*x;
    }
    printf("%lf\n",sum);
}