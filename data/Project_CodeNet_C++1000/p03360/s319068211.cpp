#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int64_t> vec(3);
  cin>>vec.at(0);
  cin>>vec.at(1);
  cin>>vec.at(2);
  int64_t K;
  cin>>K;
  sort(vec.begin(),vec.end());
  cout<<vec.at(0)+vec.at(1)+vec.at(2)*pow(2,K)<<endl;
  
    
  
}