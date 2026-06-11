#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  for(int a=1;a<=3500;a++)
    for(int b=1;b<=3500;b++)
      if(4*a*b-a*N-b*N>0 && N*a*b%(4*a*b-a*N-b*N)==0){
        cout<<a<<' '<<b<<' '<<N*a*b/(4*a*b-a*N-b*N)<<endl;
        return 0;
      }
}