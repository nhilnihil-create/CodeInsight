#include<iostream>
using namespace std;
int main(){
    int A,B,sum=0,i,t,a=0;
    cin>>A>>B;
    for(i=A;i<=B;i++){
      t=i;
     while(i>0){
        a=a*10+i%10;
        i=i/10;
    }
    if(a==t){
        sum++;
    }
    a=0;
    i=t;
    }
    cout<<sum;
    return 0;
}
