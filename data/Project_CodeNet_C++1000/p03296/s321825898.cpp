#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
 int N,cnt=0;
  cin>>N;
  int a[N];
  for(int i=0;i<N;i++) cin>>a[i];
  for(int i=0;i<N;i++){
    if(a[i]==a[i+1]){
      a[i+1]=10000-cnt;
      cnt++;
      i=0;
    }
  }
  cout<<cnt<<endl;
}	
