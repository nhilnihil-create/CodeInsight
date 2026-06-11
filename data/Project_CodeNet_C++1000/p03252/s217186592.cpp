#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
string S,T;
  cin>>S>>T;
vector<vector<int>> s(26,vector<int>());
vector<vector<int>> t(26,vector<int>());
for(int i=0;i<S.size();i++){
 s[S[i]-'a'].push_back(i);
 t[T[i]-'a'].push_back(i);
}
  
int ans=0;
int ta;
  for(int i=0;i<26;i++){
    if(s[i].size()>0){
        ta=(int)(T[s[i][0]]-'a');//s[i]におけるt[ta]
      if(t[ta].size()==s[i].size()){
        for(int j=0;j<s[i].size();j++){
          if((int)(s[i][j])!=(int)(t[ta][j])){ans=1;}
        }
      }
      else{ans=1;}
    }
  }

  if(ans==1){
  cout<<"No"<<endl;
  }
  else{cout<<"Yes"<<endl;}
  
  //cout<<s[0][1]<<endl;
}
