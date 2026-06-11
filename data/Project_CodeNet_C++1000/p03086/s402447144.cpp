#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int l=s.length();
  vector<int> count(10);
  int j=0;
  for(int i=0;i<l;i++){
    if(s.at(i)=='A' || s.at(i)=='C' || s.at(i)=='G' || s.at(i)=='T'){
      count[j]++;
    }else{
      j++;
    }
  }
  sort(count.begin(),count.end());
  reverse(count.begin(),count.end());
  cout<<count[0]<<endl;
}