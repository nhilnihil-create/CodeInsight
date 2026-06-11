#include<bits/stdc++.h>

const int INF = 1e9 + 9;

using namespace std;

bool exact(int idx, int K, vector<int>& A){
  int left = idx, right = idx;
  
  for(int i = idx; i > max(idx - K, -1); --i){
    if(A[i] >= A[idx]) left = i;
    else break;
  }
  
  for(int i = idx; i < min(idx + K, (int)A.size()); ++i){
    if(A[i] >= A[idx]) right = i;
    else break;
  }
  
  return right - left + 1 >= K;
}

int main(){
  int N, K, Q;
  cin >> N >> K >> Q;
  
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  
  int min_diff = INF;
  for(int i = 0; i < N; ++i){
    int erasable = 0;
    int len = 0;
    vector<int> max_candidate;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int j = 0; j < N; ++j){
      if(A[j] >= A[i]){
        ++len;
        pq.push(A[j]);
      }else{
        if(len - K + 1 >= 0){
          erasable += len - K + 1;
          for(int k = 0; k < len - K + 1; k++){
            max_candidate.push_back(pq.top());
            pq.pop();
          }
        }
        
        while(pq.size()) pq.pop();
        len = 0;
      }
    }
    
    if(len - K + 1 >= 0){
      erasable += len - K + 1;
      for(int k = 0; k < len - K + 1; k++){
        max_candidate.push_back(pq.top());
        pq.pop();
      }
    }
    
    if(erasable >= Q && exact(i, K, A)){
      sort(max_candidate.begin(), max_candidate.end());
      min_diff = min(max_candidate[Q - 1] - A[i], min_diff);
    }
  }
  
  cout << min_diff << endl;
  
  return 0;
}