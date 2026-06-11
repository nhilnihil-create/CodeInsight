#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> vec1(3);
  vector<int> vec2(3);
  vector<int> vec3(3);
  bool chk = true;
  
  cin >> vec1.at(0) >> vec1.at(1) >> vec1.at(2);
  cin >> vec2.at(0) >> vec2.at(1) >> vec2.at(2);
  cin >> vec3.at(0) >> vec3.at(1) >> vec3.at(2);
  
  if(vec1.at(1) - vec1.at(0) != vec2.at(1) - vec2.at(0) || vec1.at(1) - vec1.at(0) != vec3.at(1) - vec3.at(0)){
    chk = false;
  }
  if(vec1.at(2) - vec1.at(1) != vec2.at(2) - vec2.at(1) || vec1.at(2) - vec1.at(1) != vec3.at(2) - vec3.at(1)){
    chk = false;
  }
  
  if(chk == true){
    cout << "Yes";
  }else{
    cout << "No";
  }
}
