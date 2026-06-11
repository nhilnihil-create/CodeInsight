#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int64_t>A(N);
  cin>>A.at(0);
  if(A.at(0)!=0){
    cout << -1;
    return 0; 
  }
  int64_t count = 0;
  for(int i=1;i<N;i++){
    cin>>A.at(i);
  	if(A.at(i-1)+1 == A.at(i)){
      count++;
    }else if(A.at(i-1)+1 < A.at(i)){
      cout << -1;
      return 0; 
    		
    }else{
      count+=A.at(i);
    }
  }

  cout << count << endl;
}