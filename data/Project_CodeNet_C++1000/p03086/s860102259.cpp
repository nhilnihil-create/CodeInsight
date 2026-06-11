#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
  string N;
  cin >> N;
  int s = 0;
  vector<int>a(N.size());
  int maxi;
  for (int i = 0; i < (int)N.size(); i++){
    char n = N[i];
    if ((n == 'A')||(n == 'C')||(n == 'G')||(n == 'T')){
      s++;
      a.at(i) = s;
    }
    else {
      s=0;
    }
    a.at(i) = max(a.at(i),s);
  }
  maxi = *max_element(a.begin(),a.end());
  cout << maxi << endl;
}