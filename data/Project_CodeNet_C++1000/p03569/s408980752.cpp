#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)

using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;



int main(){
  string s;
  cin>>s;

  string t="";
  rep(i, s.size()){
    if(s[i]!='x') t+=s[i];
  }

  string u = "";

  u += t;
  reverse(u.begin(), u.end());

  //cout <<u<<endl;
  ll ans;
  if(u==t) {
    ans = s.size()-u.size();
    // if((s.size()+ans)%2==1 && u.size()%2==0) ans--;

    ll lc=0; ll rc=0;
    int l =0;
    int r=s.size()-1;
    while(l<=r){
      //cout<<rc<<lc<<s[l]<<l<<r<<endl;;
      if(l==r && s[l]=='x') {
	ans = rc+lc;
	//cout<<rc<<lc;

	break;
      }
      else if(l==r && s[l]!='x'){
	ans = rc+lc;
	break;	
      }
      
      else if(l+1==r) {
	if(s[l]==s[r]) {ans=rc+lc;break;}
	else{ans = rc+lc+1;break;}	
      }

      //cout << s[l]<<" " <<s[r]<<endl;
      if(s[l]!=s[r]) {
	if(s[l]=='x') {rc++; l++;}
	else {lc++;r--;}
      }
      else{l++;r--;}
      
    }
    
    
  }
  else ans = -1;
  
  cout << ans << endl;

}
