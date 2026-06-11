#include<bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;++i) cin >> a[i];

  long long res=0;
  int right=0;
  int sum=0;
  for(int i=0;i<n;++i){
    while(right<n && (sum^a[right])==(sum+a[right])){
      sum+=a[right];
      ++right;
    }
    res+=right-i;
    if(i==right) ++right;
    else sum-=a[i];
  }

  cout << res << endl;
  return 0;
}
