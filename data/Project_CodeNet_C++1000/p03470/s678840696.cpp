#include<bits/stdc++.h>
using namespace std;
 
#define ll long long

signed main()
{
  int N; cin >> N;
  vector<int> vec(N);
  for(int i = 0; i<N; ++i){
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  
  int dan = 0,mini = 0;
  for(int i = 0; i<N; ++i){
    if(vec[i]>mini) {++dan; mini = vec[i];}
  }
  cout << dan << "\n";
}
