#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main()
{
  int n; cin >> n;
  vector<int> vec(n);
  for(int i = 0; i<n; ++i){
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());

  int sumA = 0,sumB = 0;

  for(int i = 0; i<n; ++i){
    if(i%2==0){
      sumA += vec[i];
    }else{
      sumB += vec[i];
    }
  }

  cout << (sumA-sumB) << "\n";
}