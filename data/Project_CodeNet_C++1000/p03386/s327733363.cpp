#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k;
  cin>>a>>b>>k;
  int kazu=b-a+1;
  int count=0;
  for(int i=a;i<=b;i++){
    count++;
    if(count<=k||count-1>=kazu-k){
      cout<<i<<endl;
    }
  }
  return 0;
}
  