#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main()
{
  int n;
  cin >> n;
  
  int d[n];
  string s[n];
  int p[n];
  rep(i,n){
    cin >> s[i] >> p[i];
    d[i] = i+1;
  }
  
  for(int i = 0; i < n; i++){
    for(int j = n-1; j > i; j--){
      if(s[j] < s[j-1]){
        string tmps = s[j];
        s[j] = s[j-1];
        s[j-1] = tmps;
        
        int tmpi = p[j];
        p[j] = p[j-1];
        p[j-1] = tmpi;
        
        int tmpd = d[j];
        d[j] = d[j-1];
        d[j-1] = tmpd;
      }
    }
  }
  
   for(int i = 0; i < n; i++){
    for(int j = n-1; j > i; j--){
      if(s[j] == s[j-1] && p[j] > p[j-1]){
        string tmps = s[j];
        s[j] = s[j-1];
        s[j-1] = tmps;
        
        int tmpi = p[j];
        p[j] = p[j-1];
        p[j-1] = tmpi;
        
        int tmpd = d[j];
        d[j] = d[j-1];
        d[j-1] = tmpd;
      }
    }
  }
  
  rep(i,n){
    cout << d[i] << endl;
  }
  
}