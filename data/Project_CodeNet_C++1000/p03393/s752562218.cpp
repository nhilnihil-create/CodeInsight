#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >> S;
  int N=S.size();
  if(N<26){
    vector<bool> alp(26,false);
    for(int i=0;i<N;i++){
      alp[S[i]-'a']=true;
    }
    for(int i=0;i<=25;++i){
      if(alp[i]){
        continue;
      }
      else{
        S+=(char)((int)'a'+i);
        break;
      }
    }
    cout << S << endl;
    return 0;
  }
  int next=25;
  int flag=-1;
  int change=-1;
  set<int> set;
  for(int i=0;i<26;i++){
    if(S[i]-'a'==next){
      set.insert(S[i]-'a');
      while(set.count(next)){
        --next;
      }
    }
    else{
      flag=i;
      set.insert(S[i]-'a');
      change=S[i]-'a';
      while(set.count(change)){
        ++change;
      }
    }
  }
  if(flag==-1){
    cout << -1 << endl;
    return 0;
  }
  vector<bool> seen(26,false);
  string T="";
  for(int i=0;i<flag;i++){
    seen[S[i]-'a']=true;
    T+=S[i];
  }
  T+=(char)(change+(int)'a');
  seen[change]=true;
  cout << T << endl;
  return 0;
}