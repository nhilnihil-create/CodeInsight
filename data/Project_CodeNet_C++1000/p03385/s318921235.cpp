#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<char> s(3);
  cin>>s.at(0)>>s.at(1)>>s.at(2);
  sort(s.begin(),s.end());
  if(s.at(0)=='a'&&s.at(1)=='b'&&s.at(2)=='c'){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}