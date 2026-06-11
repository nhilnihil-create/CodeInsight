#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  map<long,long> a;
  vector<long> key;
  cin >> n;
  for(int i=2;i<=n;i++) {
    long x=i;
    while(x%2==0) {
      a[2]++;
      if(a[2]==1) key.push_back(2);
      x/=2;
    }
    while(x%3==0) {
      a[3]++;
      if(a[3]==1) key.push_back(3);
      x/=3;
    }
    while(x%5==0) {
      a[5]++;
      if(a[5]==1) key.push_back(5);
      x/=5;
    }
    while(x%7==0) {
      a[7]++;
      if(a[7]==1) key.push_back(7);
      x/=7;
    }
    if(x!=1) {
      a[x]++;
      if(a[x]==1) key.push_back(x);
    }
  }

  if(a[2]>=74) ans++;
  
  for(long i=0;i<key.size();i++) {
    for(long j=0;j<key.size();j++) {
      if(i!=j&&(a[key[i]]>=24&&a[key[j]]>=2)) ans++;
    }
  }
  for(long i=0;i<key.size();i++) {
    for(long j=0;j<key.size();j++) {
      if(i!=j&&(a[key[i]]>=14&&a[key[j]]>=4)) ans++;
    }
  }
  for(long i=0;i<key.size();i++) {
    for(long j=0;j<key.size();j++) {
      for(long k=j+1;k<key.size();k++) {
        if((i!=j&&i!=k)&&(a[key[i]]>=2&&(a[key[j]]>=4&&a[key[k]]>=4))) ans++;
      }
    }
  }
  cout << ans << endl;
}