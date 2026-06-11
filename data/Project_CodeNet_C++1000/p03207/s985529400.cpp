#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++){
    cin >>vec[i];
  }
   sort(vec.begin(), vec.end()); 
   reverse(vec.begin(), vec.end());
  int wa=0;
  vec[0]=(vec[0])/2;
  for(int i=0;i<n;i++)
    wa += vec[i];
  
  
 cout << wa <<endl; 
 
}
