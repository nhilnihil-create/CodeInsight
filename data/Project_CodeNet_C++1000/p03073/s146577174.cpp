#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  string S; cin >> S;
  int ans1 = 0;
  int ans2 = 0;
  for(int i=0;i<S.size();i++){
    if(i%2 == 0){
      if(S.at(i) == '0'){
        ans1++;
      }else{
        ans2++;
      }
    }else{
      if(S.at(i) == '0'){
        ans2++;
      }else{
        ans1++;
      }
    }
  }
  cout << min(ans1,ans2) << endl;
}