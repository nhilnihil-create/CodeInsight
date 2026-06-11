#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int N,d,i,count=0,dist[110]={0};
  
  cin >> N;
  
  for(i=0;i<N;i++) {
    cin >> d;
    dist[d]++;
  }
  
  for(i=0;i<110;i++) {
    if(dist[i]!=0) count++;
  }
  
  cout << count << endl;
  
  return 0;
}