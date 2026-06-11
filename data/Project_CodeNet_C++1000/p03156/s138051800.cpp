#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n,a,b;
  cin>>n>>a>>b;
  vector<int> v(3);
  for(int i=0;i<n;i++){
    int p;
    cin>>p;
    v[(p<=a)+(p<=b)]++;
  }
  cout<<*min_element(v.begin(),v.end())<<"\n";
}
