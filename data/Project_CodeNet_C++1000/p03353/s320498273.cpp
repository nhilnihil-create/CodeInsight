
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
  map<string,int> mp;
  string S;
  vector<string> sub;
  cin>>S;
  int K; cin>>K;
  int flag=-1;
  for(int i=0; i<S.size(); i++){
    for(int j=1; j<=K; j++){
      string t=S.substr(i,j);
      //cout<<t<<endl;
      if(mp.count(t)) continue;
      else{
	
	mp[t]=1;
	
	sub.push_back(t);
	
      }
    }
  }
  
  
  
  
  
  sort(sub.begin(),sub.end());
  cout<<sub[K-1]<<endl;
  //for(int i=0; i<K; i++) cout<<sub[i]<<endl;
}

