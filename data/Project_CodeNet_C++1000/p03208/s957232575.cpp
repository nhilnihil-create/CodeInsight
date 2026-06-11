#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  for(int i=0;i<n;i++){
    cin >> h.at(i);
  }
  
  sort(h.begin(),h.end());
   int sa=h.at(k-1)-h.at(0);
   //cout<<h.at(k-1)<<" "<<h.at(0)<<endl;
   for(int i=1;i<=n-k;i++){
     //cout << sa << endl;
     sa=min(sa,h.at(k+i-1)-h.at(i));
   }
   cout << sa << endl;
   return 0;
}
