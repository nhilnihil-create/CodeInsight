#include <bits/stdc++.h>
#define rep(i,n) for (int i =0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s,t;
  string ans;
  bool flag=false;
  cin >> s >> t;
  reverse(s.begin(),s.end());reverse(t.begin(),t.end());
  for(int i =0;i<s.size();i++){
    if(flag==false)for(int j=0;j<t.size();j++){
	if(s[i+j]!=t[j]&&s[i+j]!='?')break;
	if(j==t.size()-1){
	  flag=true;
	  s.replace(i,t.size(), t);
	}
      }
    if(s[i]=='?')s[i]='a';
  }
  reverse(s.begin(),s.end());
  flag==true?cout << s << endl:cout << "UNRESTORABLE" << endl;
}
