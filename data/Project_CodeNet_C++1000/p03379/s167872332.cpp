#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,n,a[200010];
  vector<int> x;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    x.push_back(a[i]);
  }
  sort(x.begin(),x.end());
  for(i=0;i<n;i++){
    if(a[i]<=x[(n-1)/2]){
      cout << x[n/2] << endl;
    }
    else{
      cout << x[(n-1)/2] << endl;
    }
  }
  return 0;
}