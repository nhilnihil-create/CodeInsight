#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n = 6,a;
  vector<int> v(4,0);
  while(n--){
    cin >> a;
    v.at(a-1)++;
  }
  sort(v.begin(),v.end());
  if(v.at(0)==1&&v.at(1)==1&&v.at(2)==2&&v.at(3)==2)cout << "YES"<<endl;
  else cout << "NO"<<endl;
}