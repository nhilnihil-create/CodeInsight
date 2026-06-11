#include<bits/stdc++.h>
using namespace std;
int main(){
     long double a,b;
    cin>>a>>b;
    long double temp=(unsigned long long)pow(b,1/a);
    unsigned long long kq=1;
    for(unsigned long long i=temp;i>=2;i--){
        unsigned long long dem=0,j=b;
        
        while(j%i==0){
            dem++;
            j=j/i;
        }
        if(dem>=a){
            kq=i;
            break;
        }
    }
    cout<<kq;
    //cout<<temp<<endl;
}