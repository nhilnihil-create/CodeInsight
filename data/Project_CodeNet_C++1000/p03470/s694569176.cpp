#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N=0;
  cin >> N;
  vector<int> d(N);
  for(int i=0;i<N;i++){
   cin >> d.at(i); 
  }
  
  sort(d.begin(),d.end());
  reverse(d.begin(),d.end());
  
  int count=1;
  
  for(int i=0;i<N-1;i++){
    if(d.at(i)>d.at(i+1)){
     count+=1; 
    }
  }
  
  cout << count << endl;
  return 0; 
}