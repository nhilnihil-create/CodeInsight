#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,y;
  cin>>n>>y;
  bool ans=0;
  int ans_x;
  int ans_y;
  int ans_z;
  for(int xn=0; xn*10000 <= y; xn++){
    for(int yn=0; xn*10000+yn*5000 <= y; yn++){
      if(xn*10000+yn*5000+(n-xn-yn)*1000==y){
        ans=1;
        ans_x=xn; ans_y=yn; ans_z=n-xn-yn;
      }
    }
  }
  if(ans){
    cout<<ans_x<<" "<<ans_y<<" "<<ans_z<<endl;
  }else{
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
  }
}


