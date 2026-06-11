#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
typedef long long ll;

int main(){
  int N,M;
  cin >> N >> M;
  ll A[N];
  int B[M];
  ll C[M];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  for(int i=0;i<M;i++){
    cin >> B[i] >> C[i];
  }
  vector<pair<int,int> > all;
  for(int n=0;n<N;n++){
    all.push_back(make_pair(-A[n],1));
  }
  for(int n=0;n<M;n++){
    all.push_back(make_pair(-C[n],B[n]));
  }
  sort(all.begin(),all.end());
  int j=0;
  int num=0;
  ll sum=0;
  while(1){
    for(int i=0;i<all[j].second;i++){
      sum += -all[j].first;
      num++;
      if(num==N) break;
    }
    j++;
    if(num==N) break;
  }
  cout << sum << endl;
}
