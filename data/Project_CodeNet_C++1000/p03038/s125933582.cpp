#include<bits/stdc++.h>
using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first > b.first;
    }
}

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A[i];
  
  vector<pair<int,int>> bc(M);
  for(int i=0; i<M; i++) cin >> bc[i].first >> bc[i].second;
  
  sort(A.begin(), A.end(), greater<int>());
  sort(bc.begin(), bc.end(), compare_by_b);
  
  long long sum=0;
  int count =0;
  int i=0;
  int j=0;
  while(true){
    if(A[i]>bc[j].second){
      sum += A[i];
      i += 1;
      count += 1;
    }else{
      sum += bc[j].second;
      bc[j].first -= 1;
      count += 1;
      if(bc[j].first==0){
        j += 1;
      }
    }
    
    if(count==N) break;
  }
  
  cout << sum << endl;

}