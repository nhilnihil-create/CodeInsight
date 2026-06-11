#include<bits/stdc++.h>
using namespace std;
int main(){
  int N , K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i< N; i++) cin >> A.at(i);
  int count[200200] = {0};
  for(int i = 0; i < A.size(); i++){
    count[A.at(i)] ++;
  }
  sort(count, count + A.size());
  reverse(count, count + A.size());

int sum = 0;
for(int i = 0; i < K; i++){
  sum+= count[i];
}
cout << N - sum << endl;
}