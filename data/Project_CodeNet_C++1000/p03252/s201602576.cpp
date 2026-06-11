#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

void f(string s,vector<int> &a){
  vector<int> seen(26);
  int p = 1;
  rep(i,int(s.size())){
    if(seen[s[i]-'a']){
      a[i]=seen[s[i]-'a'];
    }else{
      seen[s[i]-'a'] = p;
      a[i]=p;
      p++;
    }
  }
}

int main(){  
  string s,t;
  cin>>s>>t;
  int n = s.size();
  vector<int> a(n),b(n);
  
  f(s,a); f(t,b);
  
  rep(i,n){
    if(a[i]==b[i]) continue;
    puts("No");
    return 0;
  }
  puts("Yes");
}