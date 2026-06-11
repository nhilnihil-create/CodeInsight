#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<double> money(N);
  vector<string> type(N);
  for(int i=0;i<N;i++){
    cin>>money[i]>>type[i];
  }
  
  double ans=0;
  
  
  for(int i=0;i<N;i++){
    if(type[i]=="JPY"){
      ans+=money[i];
    }
    else{
      ans+=(money[i]*380000);
    }
  }
  
  printf("%.10f",ans);
}