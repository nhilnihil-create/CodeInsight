#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(int i) {
  if(i==0||i==1) return false;
  for(int j=2;j*j<=i;j++) {
    if(i%j==0) return false;
  }
  return true;
}

int isLike2017(int i) {
  if(isPrime(i)&&isPrime((i+1)/2)) return 1;
  return 0;
}

int main() {
  vector<int> s(100005,0);
  int q;
  cin>>q;
  int l,r;
  for(int i=0;i<100000;i++) {
    s[i+1]=s[i]+isLike2017(i);
  }
  for(int i=0;i<q;i++) {
    cin>>l>>r;
    cout<<s[r+1]-s[l]<<endl;
  }
}
