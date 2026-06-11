#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

int n,q;
string s;
const int q_max=2e5+2;
char t[q_max],d[q_max];

bool ljudge(int pos){
  int cpos=pos;
  rep(i,q){
    if(s[cpos]==t[i]){
      if(d[i]=='L') cpos--;
      else cpos++;
      if(cpos<0){
	return true;
      }
    }
  }
  return false;
}

bool rjudge(int pos){
  int cpos=pos;
  rep(i,q){
    if(s[cpos]==t[i]){
      if(d[i]=='L') cpos--;
      else cpos++;
      if(cpos>=n){
	return true;
      }
    }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  cin >> s;
  rep(i,q){
    cin >> t[i] >> d[i];
  }
  if(ljudge(n-1) || rjudge(0)){
    cout << 0 << endl;
    return 0;
  }
  int ans=0;
  int ub=n;  
  int lb=0;
  int left=ub;
  if(ljudge(0)){
    while(ub-lb>1){
      int mid=(ub+lb)/2;
      if(ljudge(mid)) lb=mid;
      else {
	ub=mid;
      }
    }
    left=ub;
  }
  else left=0;//安全

  ub=n;lb=0;
  int right=lb;
  if(rjudge(n-1)){
    while(ub-lb>1){
      int mid=(ub+lb)/2;
      if(rjudge(mid)) ub=mid;
      else {
	lb=mid;
      }
    }
    right=lb;
  }
  else right=n-1;
  //  cout << left << " " << right << endl;
  cout << max(right - left +1,0) << endl;

  
  return 0;
    

}
