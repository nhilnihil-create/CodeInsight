#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string S;
  cin >> S;
  
  ll num=(ll)stoll(S);
  string S2=S.substr(0,1);

  if(S.size()==1){
    cout << S << endl;
    return 0;
  }
  int i,co=0;
  for(i=1;i<(int)S.size();i++){
    string S3=S.substr(i,1);
    co+=stoi(S3);
    if(stoi(S3)!=9)
      break;
  }
 // cout << S.at(i) << endl;
 // cout << i << endl;
  if(i==S.size()){
    cout << co+stoi(S2) << endl;
    return 0;
  }
    
  	//cout << S.at(0) << endl;
    cout << ((int)S.size()-1)*9+(ll)stoi(S2)-1<< endl;
    

 // cout << pow(10,1)<< endl;
  
}