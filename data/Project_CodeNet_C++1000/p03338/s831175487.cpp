#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  
  int ma=0;
  for(int i=1;i<n;i++){
    vector<int> A(26),B(26);
    for(int j=0;j<i;j++){
      A[s[j]-'a']++;
    }
    for(int j=i;j<n;j++){
      B[s[j]-'a']++;
    }
    int cnt=0;
    for(int j=0;j<26;j++){
      if(A[j]>0 && B[j]>0) cnt++;
    }
    ma=max(ma,cnt);
  }
  cout<<ma<<endl;

  return 0;
}