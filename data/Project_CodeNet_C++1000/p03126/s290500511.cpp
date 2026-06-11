#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,w=0,cnt=0;
  cin >> n >>m;
  int a[n];
  vector<int> s((1<<19),0);
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    for(int j=0;j<k;j++){
      cin >> a[i];
      s[a[i]]++;
      w=max(w,a[i]);
    }
  }
  for(int i=0;i<=w;i++)if(s[i]==n)cnt++;
  cout << cnt << endl;
}