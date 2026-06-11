#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  int n=s.size();
  if(n<26){
    map<char,int> mp;
    char a='a';
    for(int i=0;i<26;++i){
      mp['a'+i]++;
    }
    for(int i=0;i<n;++i){
      mp[s[i]]++;
    }
    bool ok=true;
    for(auto p : mp){
      if(p.second==1 && ok==true){
        s=s+p.first;
        ok=false;

      }
      //cout << p.first << p.second << endl;
    }
    cout << s << endl;
    return 0;
  }else{
    if(s=="zyxwvutsrqponmlkjihgfedcba"){
      cout << "-1" << endl;
      return 0;
    }

    string ans;
    string x=s;
    next_permutation(x.begin(),x.end());
    for(int i=0;i<26;++i){
      if(s[i]==x[i]){
        ans+=x[i];
      }else{
        ans+=x[i];
        break;
      }
    }
    //next_permutation(ans.begin(),ans.end());
    cout << ans << endl;
  }
  return 0;
}
