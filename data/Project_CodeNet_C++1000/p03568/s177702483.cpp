#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  long long even;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(a%2==0) even++;
  }
  long long ans=1;
  for(long long i=0;i<n;i++) ans*=3;
  long long out=1;
  for(long long i=0;i<even;i++) out*=2;
  cout<<ans-out<<endl;
}
