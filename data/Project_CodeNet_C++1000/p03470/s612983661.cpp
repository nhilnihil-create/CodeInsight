#include <bits/stdc++.h>
using namespace std;
 
int main() {
  short int N,sum=1;
  cin >> N;
  vector<short int> d(N);
  short int i;
  for(i=0;i<N;++i)
    cin >> d.at(i);
  sort(d.begin(), d.end(), greater<int>());
  for(i=0;i<N;++i){
    if(i<(N-1))
      if(d.at(i)>d.at(i+1))
        ++sum;
  }
  cout << sum << endl;
}
