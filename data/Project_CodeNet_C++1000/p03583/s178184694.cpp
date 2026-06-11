#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  for(int h=1;h<=3500;h++)
    for(int n=1;n<=3500;n++)
      if((4*h*n-N*h-N*n)>0 && N*h*n%(4*h*n-N*h-N*n)==0){
        cout<<h<<' '<<n<<' '<<N*h*n/(4*h*n-N*h-N*n)<<endl;
        return 0;
      }
}