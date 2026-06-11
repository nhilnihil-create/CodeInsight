#include <bits/stdc++.h>
using namespace std;

int N;
int h[1000];

bool isAllZero(){
  for (int i = 0; i < N; i++) {
    if ( h[i]!=0 ) return false;
  }
  return true;
}

int countGroups(){  
  int before = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if ( h[i]!=0 && before==0) count++;
    before = h[i];
  }
  return count;
}

void decrementH(){
  for (int i = 0; i < N; i++) {
    if(h[i]!=0) h[i]--;
  }
}

int main(){
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  
  int i = 0;
  while(!isAllZero()){
    int groups = countGroups();
    i += groups;
    
    decrementH();
  }
  cout << i << endl;
  
  return 0;
}