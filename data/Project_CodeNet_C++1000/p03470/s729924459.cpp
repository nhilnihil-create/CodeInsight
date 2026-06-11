#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,i,counter;
  counter=1;
  cin >> n;
  vector<int>vec(n);
  for(i=0;i<n;i++){
    cin >> vec.at(i);  
}  
  sort(vec.begin(),vec.end());
  int ma=vec.at(0);
  for(i=0;i<n;i++){
    if(vec.at(i)>ma){
      counter++;
      ma=vec.at(i);
    }
    else
      continue;
  }
  cout << counter << endl;
} 
