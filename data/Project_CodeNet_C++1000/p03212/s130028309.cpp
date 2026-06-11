#include <bits/stdc++.h>
using namespace std;

bool judge(string & s){
  bool three=false;
  bool five=false;
  bool seven=false;
  for(int i=0;i<s.size();i++){
    if(s.at(i)=='3'){
      three=true;
    }else if(s.at(i)=='5'){
      five=true;
    }else if(s.at(i)=='7'){
      seven=true;
    }
  }
  return three&&five&&seven;
}

int main(){
  int N;
  cin >> N;
  int ans=0;
  string tfs="357";
  queue<string> que;
  que.push("3");
  que.push("5");
  que.push("7");
  string s;
  while(1){
    s=que.front();
    que.pop();
    if(s.size()>=10){
      break;
    }
    if(stoi(s)<=N){
      if(judge(s)){
        ans++;
      }
    }else{
      break;
    }
    for(auto c:tfs){
      que.push(s+c);
    }
  }
  cout << ans << endl;
  return 0;
}
