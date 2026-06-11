#include <iostream>
using namespace std;

int digitsum(int n){
    int sum=0;
    
    while(n){
        int rem= n%10;
        sum+=rem;
        n/=10;
    }
    return sum;
}
int main(void){
    // Your code here!
   int n;
   cin>>n;
   
   int a,b;
   cin>>a>>b;
   int sum =0;
   for(int i=1;i<=n;i++){
       int dsum=digitsum(i); 
       if(dsum>=a && dsum<=b){
           sum+=i;
       }
   }
cout<<sum;
    
}
