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
    ABC127();
}

void ABC127(){
    int r,D,x,x_next;
    cin>>r>>D>>x;
    for(i=0;i<10;i++){
        x_next=r*x-D;
        cout<<x_next<<endl;
        x=x_next;
    }
}
