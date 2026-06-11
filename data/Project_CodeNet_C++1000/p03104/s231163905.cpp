#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  long a,b;
  cin >> a>>b;
  b++;
  vector<long>ans(40);
  rep(i,40){
    long cob=b/(long)pow(2,i+1)*(long)pow(2,i)+max(0L,b%(long)pow(2,i+1)-(long)pow(2,i));
    long coa=a/(long)pow(2,i+1)*(long)pow(2,i)+max(0L,a%(long)pow(2,i+1)-(long)pow(2,i));
    ans.at(i)=(cob-coa)%2;
  }
  long co=0;
  rep(i,40){
    co+=(long)pow(2,i)*ans.at(i);
  }
  cout<<co<<endl;
}