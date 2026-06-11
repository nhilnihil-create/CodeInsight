#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int sum;
  int max = 0;
  int ssize = s.size();
  for(int i=0;i <= ssize;i++){
    if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T'){
      sum++;
    }else{
      if(sum>max){
        max=sum;
      }
      sum = 0;
    }
  }
  cout << max << endl;
  return 0;
}
