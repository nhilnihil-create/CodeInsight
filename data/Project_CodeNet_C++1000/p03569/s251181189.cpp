#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  string s;
  cin>>s;
  int left=0, right=s.size()-1;
  int cnt=0;
  while(right-left>0){
    if(s[left]=='x' && s[right]=='x'){
      left++; right--;
    }else if(s[left]=='x' && s[right]!='x'){
      left++; cnt++;
    }else if(s[left]!='x' && s[right]=='x'){
      right--; cnt++;
    }else{
      if(s[left]==s[right]){
        left++; right--;
      }else{
        cnt=-1; break;
      }
    }
  }
  cout<<cnt<<endl;
}

