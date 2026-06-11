#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,M;
  cin >> N >> M;
vector<vector<int64_t>> data(N ,vector<int64_t>(3));
  for(int i=0;i < N;i++){
  for(int j=0;j < 3;j++){
  cin >> data.at(i).at(j);
  }
  }
  
  int64_t m=0;
  int64_t sum=0;
vector<int64_t> datb(N, 0);
  for(int i=0;i < N;i++){
  datb.at(i) = data.at(i).at(0)+data.at(i).at(1)+data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = data.at(i).at(0)+data.at(i).at(1)-data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = data.at(i).at(0)-data.at(i).at(1)+data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = -data.at(i).at(0)+data.at(i).at(1)+data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = data.at(i).at(0)-data.at(i).at(1)-data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = -data.at(i).at(0)+data.at(i).at(1)-data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = -data.at(i).at(0)-data.at(i).at(1)+data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  for(int i=0;i < N;i++){
  datb.at(i) = -data.at(i).at(0)-data.at(i).at(1)-data.at(i).at(2);
  }
  sort(datb.begin(), datb.end());
  sum=0;
  for(int i=0;i < M;i++){
  sum += datb.at(N-1-i);
  }
  m = max(m, sum);
  
  cout << m;
}