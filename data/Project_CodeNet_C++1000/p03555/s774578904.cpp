#include <bits/stdc++.h>
using namespace std;
int main(){
string moji;
  cin>>moji;
  string mojimoji;
  cin>>mojimoji;
  if(moji.at(0)==mojimoji.at(2) && moji.at(1)==mojimoji.at(1) && moji.at(2)==mojimoji.at(0)){
  cout<<"YES";
  }
  else{
  cout<<"NO";
  }

}