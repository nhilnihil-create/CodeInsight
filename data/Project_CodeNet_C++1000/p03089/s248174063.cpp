#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  int n;  cin >> n;
  vector<ll> a(n); 
  
  for(int i=0; i<n; i++) cin >> a.at(i);
    
  vector<ll> res;
  for(int i=0; i<n; i++){
    int pivot=-1;
    for(int j=a.size()-1; 0<=j; j--){
      if(a[j]==j+1){
        pivot = j; break;
      }
    }
    if(pivot==-1){
      cout << -1 << endl;
      return 0;
    }
    res.push_back(pivot+1);
    a.erase(a.begin()+pivot);
  }
  reverse(res.begin(), res.end());
  for(auto x: res) cout << x << endl;
}
