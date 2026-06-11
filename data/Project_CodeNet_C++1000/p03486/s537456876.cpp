#include<bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  for (int i = 0; i < s.size() - 1; i++){
    int min = i;                               
    for (int j = i + 1; j < s.size(); j++){
      if (s.at(j) < s.at(min)) {
        min = j;
      }
    }
    if (i != min){
      char temp = s.at(i);
      s.at(i) = s.at(min);
      s.at(min) = temp; 
    }
  }
  for (int i = 0; i < t.size() - 1; i++){
    int max = i;                               
    for (int j = i + 1; j < t.size(); j++){
      if (t.at(j) > t.at(max)) {
        max = j;
      }
    }
    if (i != max){
      char temp = t.at(i);
      t.at(i) = t.at(max);
      t.at(max) = temp; 
    }
  }
  for (int i = 0; i < t.size(); i++){
    if (i == s.size() || s.at(i) < t.at(i)){
      cout << "Yes";
      break;
    }
    else if (s.at(i) > t.at(i) || i == t.size() - 1){
      cout << "No";
      break;
    }      
  } 
}