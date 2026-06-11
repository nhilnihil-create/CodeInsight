#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  int odds=1;
  for(int x:A){
    if(x%2==0)
      odds*=2;
  }
  int ans=1;
  for(int i=0;i<N;i++){
    ans*=3;
  }
  cout<<ans-odds<<endl;
}
