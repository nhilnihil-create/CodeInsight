#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> num(4);
  for(int &x:num){
    cin>>x;
  }
  sort(num.begin(),num.end());
  vector<int> base={1,4,7,9};
  for(int i=0;i<4;i++){
    if(num[i]!=base[i]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}