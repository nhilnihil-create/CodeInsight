#include <bits/stdc++.h>
using namespace std;

int main(){
   int N;
   cin>>N;
   vector<int> V(N);
   int ans = 0;

  for(int i=0;i<N;i++){
      cin>>V.at(i);
      ans += V.at(i);
  }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
   cout<<ans-V.at(0)/2<<endl;

}
