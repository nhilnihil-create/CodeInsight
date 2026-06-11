#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
int main() {
  string s;
  cin>>s;
  if(s.size()<26){
    vector<bool>ch(26);
    rep(i,s.size()){
      ch.at(s.at(i)-'a')=true;
    }
    char c;
    rep(i,26){
      if(!ch.at(i)){
        c='a'+i;
        break;
      }
    }
    cout<<s<<c<<endl;
  }
  else{
    int n=-1;
    rep(i,s.size()-1){
      if(s.at(i)<s.at(i+1)){
        n=i+1;
      }
    }
    if(n==-1){
      cout<<-1<<endl;
    }
    else{
      vector<char>ch;
      rep2(i,n,s.size()){
        ch.push_back(s.at(i));
      }
      sort(ch.begin(),ch.end());
      rep(i,n-1){
        cout<<s.at(i);
      }
      rep(i,ch.size()){
        if(ch.at(i)>s.at(n-1)){
          cout<<ch.at(i);
          break;
        }
      }
    }
  }
}