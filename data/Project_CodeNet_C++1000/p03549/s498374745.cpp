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
   long long int x,y,sum,n2=1;
   cin>>x>>y;
   sum=y*1900+(x-y)*100;
   for(int i=0;i<y;i++){
       n2=n2*2;
   }
   cout<< sum*n2<<endl;
  return 0;
}