#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  string A,B,C;
  cin>>N>>A>>B>>C;
  long ans=0;
  for(int i=0;i<N;i++){
    vector<long> a(26);
    a[A[i]-'a']++;
    a[B[i]-'a']++;
    a[C[i]-'a']++;
    sort(a.begin(),a.end());
    ans+=3-a[25];
  }
cout<<ans<<endl;
  }
