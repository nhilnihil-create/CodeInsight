#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  vector<int> a;
  cin >> N;
  for (int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }
  sort(a.begin(), a.end(), greater<int>());

  int Alice=0,Bob=0;
  for (int i = 0; i < N; i++){
    if(i%2 == 0){
      Alice += a[i];
    }else{
      Bob += a[i];
    }
  }

  printf("%d\n", Alice - Bob);
  
}
