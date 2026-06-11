#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  double x;
  string u;
  double total=0;
  double rate=380000.0;
  for (int i=0; i<N; i++){
    cin>>x>>u;
    if (u=="JPY"){
      total+=x;
    } else {
      total+=x*rate;
    }
  }
  
 cout<<total<<endl;
}
  