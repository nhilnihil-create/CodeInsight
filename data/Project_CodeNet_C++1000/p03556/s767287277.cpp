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
    int n,ans=0;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        ans=i*i;
    }
    cout<<ans<<endl;
  return 0;
}