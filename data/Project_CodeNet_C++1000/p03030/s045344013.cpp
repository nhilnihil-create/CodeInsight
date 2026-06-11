#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  pair<pair<string,int>,int>p[1000];
  for(int i=0;i<N;i++){
    string S;
    int T;
    cin>>S>>T;
    p[i]=make_pair(make_pair(S,-T),i+1);
  }
  sort(p,p+N);
  for(int i=0;i<N;i++){
    cout<<p[i].second<< endl;
  }
}
  