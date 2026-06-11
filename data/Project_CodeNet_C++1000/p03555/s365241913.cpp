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
   string a,b;
   cin>>a>>b;
   if(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0]){
       cout<<"YES"<<endl;
   }
   else{
       cout<<"NO"<<endl;
   }
  return 0;
}