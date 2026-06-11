#include <bits/stdc++.h>
using namespace std;

int main(){
  int A , B , K ;
  cin >> A >> B >> K ;
  vector<int> D(110);
  for(int i=1;i<=100;i++){
    if(A%i==0&&B%i==0) {
      D[i]=i;
    }
  }
  
  sort(D.begin(),D.end());
  reverse(D.begin(),D.end());
  
  cout << D[K-1] << endl;
  
}


