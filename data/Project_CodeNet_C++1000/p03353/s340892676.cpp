#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int cnt=0,K_tmp;
string s;
bool flag=false;

void dfs(string subs){
  if(cnt==K_tmp){
    cout << subs << endl;
  }
  else if(cnt<=K_tmp){
    for(char c='a';c<='z';++c){
      if(s.find(subs+c)>=0 && s.find(subs+c)<s.size()){
        cnt++;
        dfs(subs+c);
      }
    }
  }
}


int main(){
  cin>>s;
  int K;cin>>K;
  K_tmp=K;
  dfs("");
}