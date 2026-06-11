#include <bits/stdc++.h>
using namespace std;
 
int main(){
   int N;
   cin>>N;
   vector<int>v(N);
   for(int i = 0; i<N;i++){
       cin>>v.at(i);
   }
   sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  cout<<v.at(0)-v.at(N-1)<<endl;
 
}