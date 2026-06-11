#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  vector<int>B(N);
  int64_t ansA=0,ansB=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    ansA+=A[i];
  }
  for(int i=0;i<N;i++){
    cin>>B[i];
    ansB+=B[i];
  }
  int64_t dis=0;int cnt=0;
  if(ansB>ansA){cout<<-1<<endl;}
  else{
    vector<int64_t>d;
    for(int i=0;i<N;i++){
      if(A[i]>B[i]){d.push_back(A[i]-B[i]);}
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    for(int i=0;i<N;i++){
     if(A[i]<B[i]){cnt++;dis=dis+B[i]-A[i];}
    }
    if(cnt==0){cout<<0<<endl;return 0;}
    for(int i=0;i<d.size();i++){
     if(d[i]>=dis){cnt++;break;}
     else{cnt++;dis-=d[i];}
    }
    cout<<cnt<<endl;return 0;
    }
  return 0;
}