#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  cin >>N;
  
  vector<int>V(N);
  vector<int>C(N);
  vector<int>div(N);
  
  for(int i = 0 ; i < N ; i++){
  	cin >> V.at(i);
  }
 
  for(int i = 0 ; i < N ; i++){
  	cin >> C.at(i);
  } 
  
  int max = 0;

  for(int i = 0 ; i < N ; i++){
	
    if(V.at(i) - C.at(i)>=0){
    	max += V.at(i) - C.at(i);
    }  
  }
  
  
 // sort(div.begin(),div.end());
  
  cout << max << endl;
  
  return 0;
  
 }
