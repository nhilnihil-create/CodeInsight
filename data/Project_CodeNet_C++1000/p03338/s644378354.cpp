#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; string s; cin >> n >> s;
  int max_reg=0;
  for(int i=0; i<n-1; i++) {
    vector<int> a0(26,0), a1(26,0);
    string s0 = s.substr(0, i);
    string s1 = s.substr(i, n-i);
    for(int j=0; j<i; j++){
	    a0[(int)(s0[j]-'a')] = 1;
    }
    for(int j=0; j<n-i; j++){
	    a1[(int)(s1[j]-'a')] = 1;
    }
    
    int reg=0;
    for(int k=0; k<26; k++){
	    if(a0[k]*a1[k]==1) reg++;
    }
    max_reg = max(max_reg, reg);
  }
  
  cout << max_reg << endl;
  return 0;
}