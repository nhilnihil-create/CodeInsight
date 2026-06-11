#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> d(N);
  for(int i=0;i<N;i++)
    cin>>d.at(i);
  sort (d.begin(),d.end());
  
  int c=1;
  int s=d.at(0);
  for(int i=0;i<N-1;i++){
    if (s<d.at(i+1)) {
      c++;
      s=d.at(i+1);
    }
  }
  cout<<c<<endl;
}