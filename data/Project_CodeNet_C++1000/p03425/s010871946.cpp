#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i=0; i<n; i++){
    cin >> s[i];
  }
  
  vector<long long> v(5);
  for(int i=0; i<5; i++){
    v[i] = 0;
  }
  
  for(int i=0; i<n; i++){
    if(s[i][0] == 'M'){
    v[0]++;
    }
  }
  for(int i=0; i<n; i++){
    if(s[i][0] == 'A'){
    v[1]++;
    }
  }
  for(int i=0; i<n; i++){
    if(s[i][0] == 'R'){
    v[2]++;
    }
  }
  for(int i=0; i<n; i++){
    if(s[i][0] == 'C'){
    v[3]++;
    }
  }
  for(int i=0; i<n; i++){
    if(s[i][0] == 'H'){
    v[4]++;
    }
  }
  
  long long sum = 0;
  
  sum = v[0]*v[1]*v[2] + v[0]*v[1]*v[3] + v[0]*v[1]*v[4] + v[0]*v[2]*v[3] + v[0]*v[2]*v[4] + v[0]*v[3]*v[4] + v[1]*v[2]*v[3] + v[1]*v[2]*v[4] + v[1]*v[3]*v[4] + v[2]*v[3]*v[4];
  cout << sum << endl;
	return 0;
}
