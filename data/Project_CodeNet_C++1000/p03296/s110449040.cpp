#include<iostream>
using namespace std;
#define df 0

int main(){
  int n; cin >> n;
  int prev; cin >> prev;
  int cnt=0;
  for(int i=1;i<n;i++){
    int temp; cin >> temp;
    if(temp==prev){
      cnt++;
      prev=0;
    }else{
      prev=temp;
    }
  }
  cout << cnt;
}

/// confirm df==0 ///
