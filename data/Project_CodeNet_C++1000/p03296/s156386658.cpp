#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
 int N; cin >> N;
  vector<int> a(N+1);
  for(int i = 0; i < N; i++){ cin >> a[i];}
  a[N] = 10001;
  
  int head = 0; int tail = 0;
  
  int cnt = 0;
  
  while( head < N && tail < N){ 
    
    if( a[tail] != a[tail+1] && tail < N){ tail++; head++; continue;}
    
    while( a[tail] == a[tail+1] && tail < N){ tail++;}
    
    cnt += (tail-head+1)/2;
    
    tail++;
    head = tail;
  }
    
  cout << cnt << endl; return 0;
} 