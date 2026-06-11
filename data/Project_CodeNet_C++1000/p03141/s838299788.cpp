#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<tuple<long long,long long,long long>> CAB(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin >> a >> b;
    CAB.at(i)=make_tuple(a+b,a,b);
  }

  sort(CAB.begin(),CAB.end());
  reverse(CAB.begin(),CAB.end());
  long long ans=0;
  for(int i=0;i<N;i++){
    int c,a,b;
    tie(c,a,b)=CAB.at(i);
    if(i%2==0)  ans+=a;
    else  ans-=b;
  }
  cout << ans << endl;

  return 0;
}