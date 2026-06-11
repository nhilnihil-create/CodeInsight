#include <bits/stdc++.h>
using namespace std;
int main(){
  int N=0, Alice=0, Bob=0;
  vector<int> a(101);
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  sort(a.rbegin(),a.rend());
  for(int i=0;i<N;i++){
    if(i%2 == 0){
      Alice+=a.at(i);
    }else{
      Bob+=a.at(i);
    }
  }
  cout << Alice-Bob << endl;
}