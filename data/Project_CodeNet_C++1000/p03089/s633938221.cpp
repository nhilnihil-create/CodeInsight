#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vec;
vector <int> ansVec;
bool flag = true;

void printAns(){
  if(flag == false) cout << -1 << endl;
  else{
    reverse(ansVec.begin(), ansVec.end());
    for(int i = 0; i < ansVec.size(); i++){
      cout << ansVec[i] + 1 << endl; 
    }
  }
}

void solveForTrue(int n){
  while(vec.empty() == false && flag == true){
    for(int i = vec.size() - 1; i >= 0; i--){
      if(vec[i] == i){  // Right Most in correct position
        ansVec.push_back(vec[i]);
        vec.erase(vec.begin() + i);
        break;
      }
      else if(vec[i] > i){
        flag = false;
      }
    }
  }
}

void solve(int n){
  solveForTrue(n);
  printAns();
}

int main() {
  int n , num;
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> num;
    vec.push_back(num-1);
  }
  solve(n);
}