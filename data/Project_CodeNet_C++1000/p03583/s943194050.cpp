#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin>>N;
  for(long h=1;h<=3500;h++){
    for(long n=1;n<=3500;n++){
      long div=4*h*n-N*h-N*n;
      if(div>0){
        if(N*h*n%div==0){
          cout<<h<<" "<<n<<" "<<N*h*n/div<<endl;
          return 0;
        }
      }
    }
  }
}
