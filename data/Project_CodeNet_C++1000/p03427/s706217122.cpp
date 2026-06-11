#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N; cin>>N;
  N+=1;
  long long a=log10(N);
  long long b=pow(10,a);
  if(N/b==1)cout<<a*9<<endl;
  else cout<<a*9+N/b-1<<endl;
}