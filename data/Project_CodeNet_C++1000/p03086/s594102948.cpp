#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  string s;
  cin >> s;

  int ans=0;
  int num=0;
  bool flag=false;

  int n=s.length();
  rep(i,n){
    string a="";
    a+=s[i];
    if(a=="A" || a=="C" ||a=="G" || a=="T"){
      if(!flag){
	flag=true;
	num=1;
      }else num++;
    }else flag=false;
    if(ans<num)ans=num;
  }
  cout << ans << endl;
}