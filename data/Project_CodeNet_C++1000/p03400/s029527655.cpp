#include <bits/stdc++.h>
using namespace std;


int main() {

  int n,d,x;
  cin>>n>>d>>x;

  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin>>A.at(i);
  }

  int sum=0;
  for(int i=0;i<n;i++){
    int eating_day=0;
    for(int j=0;j<d;j++){
      if(j==0){
        sum++;
        eating_day=A.at(i)+1;
      }
      else if(j==eating_day-1){
        sum++;
        eating_day+=A.at(i);
      }
    }
  }

  cout<<sum+x<<endl;

    return 0;
}
