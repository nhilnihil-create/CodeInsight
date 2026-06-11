#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int>moji(3);
  for(int i=0;i<3;i++){
  cin>>moji.at(i);
  }
sort(moji.begin(),moji.end());
  reverse(moji.begin(),moji.end());
  cout<<moji.at(0)*10+moji.at(1)+moji.at(2)<<endl;

}
