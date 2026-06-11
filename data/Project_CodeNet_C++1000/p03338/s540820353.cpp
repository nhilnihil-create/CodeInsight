#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  
  vector<int> num(n, 0);
  for (int i=1 ; i<n ; i++){
    vector<char> left(i);
    vector<char> right(n-i);
    for (int j=0 ; j<i ; j++){
      left.at(j) = s.at(j);
    }
    for (int j=0 ; j<n-i ; j++){
      right.at(j) = s.at(j+i);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    left.erase(unique(left.begin(), left.end()), left.end());
    right.erase(unique(right.begin(), right.end()), right.end());
    
    for (int j=0 ; j<left.size() ; j++){
      for (int k=0 ; k<right.size() ; k++){
        if (left.at(j) == right.at(k)){
          num.at(i)++;
          break;
        }
      }
    }
  }
  
  sort(num.begin(), num.end());
  
  cout << num.at(n-1) << endl;
}