#include <bits/stdc++.h>
#include <math.h>
using namespace std;
void ABC80(void);
void ABC81(void);
void ABC82(void);
void ABC83(void);
void ABC84(void);
void ABC85(void);
void ABC86(void);
void ABC87(void);
void ABC88(void);
void ABC89(void);

int main(void){
    ABC87();
}

void ABC87(){
    int a,b,c,i,j,k,x,ans=0;
    cin>>a>>b>>c>>x;
    for(i=0;i<=a;i++){
        for(j=0;j<=b;j++){
            for(k=0;k<=c;k++){
                if(x==500*i+100*j+50*k)ans++;
            }
        }
    }
    cout<<ans<<endl;
}