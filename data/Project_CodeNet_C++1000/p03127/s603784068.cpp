#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int T,i,j,x;
    int n;

    cin>>n;
    bool ok=0;

    int g;
    scanf("%d",&g);
    for(i=1;i<n;i++){
        scanf("%d",&x);
        if(!ok){
            g=gcd(g,x);
            if(g==1) ok=1;
        }

    }
    printf("%d\n",g);



return 0;
}
