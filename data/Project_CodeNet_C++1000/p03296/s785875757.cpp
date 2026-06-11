#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
#define R(i,n) for(int i = 1; i<=n; i++)
typedef long long ll;
using namespace std;

int main(){
  int n,count=0;
  cin >> n;
  vector<int> v(n,0);
  r(i,n){
    cin >> v.at(i);
    if(i>0&&v.at(i)==v.at(i-1)){
      count++;
      v.at(i)=1000;
    }
  }
  cout << count << endl;
}