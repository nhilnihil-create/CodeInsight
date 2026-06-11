#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main() {
  int n;
  cin >> n;
  ll a[n];
  for(int i=0;i<n;i++) cin >> a[i];
  int right=0;
  ll ans=0,sum=0;
  for(int left=0;left<n;left++){
    while(right<n && sum+a[right]==(sum ^ a[right])){
      sum+=a[right];
      right++;
    }
    ans += right-left;
    if(left==right) right++;
    else sum-=a[left];
  }
  cout << ans << endl;
}
