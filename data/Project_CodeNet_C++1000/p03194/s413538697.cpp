#include <iostream>
using namespace std;
long long ruijou(long long a,long long b){
    long long c=1;
    while(b>0){
        if(b%2==1){
            c*=a;
        }
        a*=a;
        b/=2;
    }
    return c;
}
int main(void){
    long long N,P,i,ans=1;
    cin>>N>>P;
    if(N==1){
        cout<<P<<endl;
        return 0;
    }
    long long a=2,b=N,c=1;
    while(b>0){
        if(b%2==1){
            c*=a;
        }
        if(a>10000000&&b>1){
            cout<<1<<endl;
            return 0;
        }
        a*=a;
        b/=2;
        
    }
    for(i=1;ruijou(i,N)<P+1;i++){
        if(P%ruijou(i,N)==0){
            ans=i;
        }
    }
    cout<<ans<<endl;
}