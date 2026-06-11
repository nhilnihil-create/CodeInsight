#include<bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int> a1(n);
  vector<int> a2(n);
  for(int i=0; i<n; i++) cin >> a1[i];
  for(int i=0; i<n; i++) cin >> a2[i];
  
  vector<int> s1(n+1, 0);
  vector<int> s2(n+1, 0);
  
  for(int i=0; i<n; i++){
    s1[i+1] = s1[i] + a1[i];
    s2[i+1] = s2[i] + a2[i];
  }
  
  
  int max_a = 0;
  for(int i=0; i<n; i++){
    max_a = max(max_a, s2[n]-s2[i]+s1[i+1]);
  }
  
  cout << max_a << endl;
  
  return 0;
}