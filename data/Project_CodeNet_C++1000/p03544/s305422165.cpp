#include <bits/stdc++.h>
using namespace std;
 


int main() {
 int n;
  cin >>n;

  vector<int64_t> lucas (n+1,0);
    lucas[0]=2;
  	lucas[1]=1;
  if(n==0)	cout << lucas[0];
  else if(n==1) cout << lucas[1];
  else if(n==2) cout <<lucas[0] +lucas[1];
  else{
    for(int i=2;i<=n;i++){
    lucas[i]=lucas[i-1]+lucas[i-2];
    }
  cout << lucas[n] <<endl;
  }
}
