#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  pair<pair<string,int>,int> P[N];
  for(int i=0;i<N;i++){
    cin>>P[i].first.first>>P[i].first.second;
    P[i].first.second*=-1;
    P[i].second=i+1;
  }
  sort(P,P+N);
  
  for(int i=0;i<N;i++){
    cout<<P[i].second<<endl;
  }
}