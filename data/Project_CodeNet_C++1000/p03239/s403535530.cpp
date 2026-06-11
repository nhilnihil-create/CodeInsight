#include <bits/stdc++.h>
#include <math.h>
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
    ABC112();
}

void ABC112(){
    int n,t,i,a,b,min=1000,sum=0;
    cin>>n>>t;
    for(i=0;i<n;i++){
        cin>>a>>b;
        if(a<min&&b<=t){
            min=a;
        }
        if(b>t)sum++;
    }
    if(sum==n)cout<<"TLE"<<endl;
    else cout<<min<<endl;
}