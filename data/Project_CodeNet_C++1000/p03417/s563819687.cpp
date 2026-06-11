#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t h,w;cin>>h>>w;
  if(h==1||w==1){
    if(h*w==1){
      cout <<1<<endl;
      return 0;
    }
    cout <<h*w-2<<endl;
    return 0;
  }
  cout <<h*w-2*h-2*(w-2)<<endl;
}