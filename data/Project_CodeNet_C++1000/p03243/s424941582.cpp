#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
  int n;
  cin>>n;
  rep(i,9){
    if(n>i*100+i*10+i&&n<=(i+1)*100+(i+1)*10+i+1){
      cout<<(i+1)*100+(i+1)*10+i+1<<endl;
    }


  }



  return 0;
}
