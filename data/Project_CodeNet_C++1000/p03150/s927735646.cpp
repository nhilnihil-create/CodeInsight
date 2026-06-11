#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  string s;
  cin>>s;
  if(s=="keyence"){
    cout<<"YES"<<endl;
    return 0;
  }
  for(int i=0;i<s.size();i++){
    for(int j=i;j<s.size();j++){
      string t="";
      for(int k=0;k<s.size();k++){
	if(k<i||k>j)t.push_back(s[k]);
      }
      if(t=="keyence"){
	cout<<"YES"<<endl;  
	return 0;
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}
