#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> vec;
  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    vec.push_back(num);
  }
  int smallest = 1000000000;
  for(int i=0; i+k-1<n; i++){
    int left = vec[i];
    int right = vec[i+k-1];
    if(right-left+min(abs(left), abs(right)) < smallest){
      smallest = right-left+min(abs(left), abs(right));
    }
  }
  cout << smallest << endl;
  return 0;
}
      
      
      
      