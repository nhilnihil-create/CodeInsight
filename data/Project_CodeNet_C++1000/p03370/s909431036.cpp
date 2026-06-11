#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,x,sum=0;
  cin >> n >> x;
  vector<int>m(n);
  for(int i=0; i<n; i++){
    cin >> m.at(i);
    sum+=m.at(i);
  }
  sort(m.begin(),m.end());
  x=x-sum;
  n+=x/m.at(0);
  cout << n << endl;
}
