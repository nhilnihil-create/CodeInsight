#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  int64_t sum_j=0,sum_b=0;;
  for(int i=0;i<n;i++){
    double x;
    string u;

    cin>>x>>u;
    if(u=="JPY"){
      sum_j+=(int64_t)x;
    }
    else
    {
      sum_b+=(int64_t)(x*(double)100000000);
    }
    


  }

  cout << std::fixed  <<(double)sum_j+(double)(sum_b*38/(double)10000)<<endl;

  return 0;

}