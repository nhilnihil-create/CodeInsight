#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
   int a,b,c;
   cin>>a>>b>>c;
   if(a==b){
       cout<<c<<endl;
   }
   else if(b==c){
       cout<<a<<endl;
   }
   else{
       cout<<b<<endl;
   }
    return 0;
}