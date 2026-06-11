#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  long double sum=0;;
  for(int i=0;i<n;i++){
    long double x;
    string u;

    cin>>x>>u;
    if(u=="JPY"){
      sum+=x;
    }
    else
    {
      sum+=x*380000.0;
    }
    


  }

  cout << std::fixed << std::setprecision(15) <<sum<<endl;

  return 0;

}
