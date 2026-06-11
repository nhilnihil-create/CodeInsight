#include <bits/stdc++.h>
using namespace std;


int main() {
long N,A,B;
cin>>N>>A>>B;
vector<long> p(N);
for(int i=0;i<N;i++) cin>>p[i];
long q1=0,q2=0,q3=0;
for(int i=0;i<N;i++){
  if(p[i]<=A) q1++;
  else if(p[i]<=B) q2++;
  else q3++;
}
cout<<min(q1,min(q2,q3))<<endl;
}
