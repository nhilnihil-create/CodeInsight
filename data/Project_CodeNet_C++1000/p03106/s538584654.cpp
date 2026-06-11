#include<bits/stdc++.h>
using namespace std;
int main(){
  int A; int B; int K;
  cin >> A >> B >> K ;
  
  int div;
  vector<int> comdiv;
  int j=0;
  int  ans;
  
  for(int i=1; i <A+1; i++){
    if(A%i==0 && B%i==0){
      comdiv.push_back(i);
    }
  }
    
  j = comdiv.size()-K;
  
  cout << comdiv.at(j) << endl;
}
