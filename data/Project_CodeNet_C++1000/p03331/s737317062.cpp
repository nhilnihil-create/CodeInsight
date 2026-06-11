#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int sum_keta(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main() {
    int n;
    cin>>n;
    int minimam=1000000;
    if(n%10==0) cout<<"10"<<endl;
    else{
        
    for(int a=1;a<=n;a++){
        int b=n-a;
        int s=sum_keta(a)+sum_keta(b);
        minimam=min(minimam,s);
    }
    cout<<minimam<<endl;
    }
}