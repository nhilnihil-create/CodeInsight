#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin>>N;
  long long h,n,w;
  for(h=N/4+1;h<=3500;h++){
    for(n=h;n<=3500;n++){
      for(w=n;w<=3500;w++){
        if(4*h*n*w==N*(n*w+h*w+h*n)){
          cout<<h<<" "<<n<<" "<<w<<endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

      
    