#include <bits/stdc++.h>
using namespace std;

int main(){
  int  N;
  scanf("%d", &N);
  vector<int> a(N);
  for(int i = 0; i < N; i++){
  	scanf("%d", &a[i]);
  }
  int answer = 0;
  for(int i = 0; i < N; i++){
  	int group_size = 1;
    while(i+1 < N && a[i] == a[i+1]){
    	group_size++;
    	i++;  
    }
    answer += (group_size/2);
  }
  cout << answer;
  return 0;
}