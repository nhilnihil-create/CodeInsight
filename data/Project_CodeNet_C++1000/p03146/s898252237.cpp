#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int m = 1000005;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  a[0]=n;
  for(int i=1;i<m;i++){
    if(a[i-1]%2==0) a[i]=a[i-1]/2;
    else a[i]=3*a[i-1]+1;
    for(int j=0;j<i;j++){
      if(a[i]==a[j]){
        cout << i+1;
        return 0;
      }
    }
  }
}