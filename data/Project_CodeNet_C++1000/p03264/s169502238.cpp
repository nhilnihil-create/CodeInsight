#include <bits/stdc++.h>
using namespace std;
const int INF=1e9+5;
typedef long long ll;

int main() {
  int N;
  cin>>N;
  if(N%2==1){
    cout<<N/2*(N/2+1)<<endl;
  }
  else{
    cout<<N/2*N/2<<endl;
  }
  
}
