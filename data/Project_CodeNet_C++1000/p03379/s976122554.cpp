#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> data1(N);
  for(int i=0; i<N; i++){
    cin >> data1[i];
  }
  vector<int> data2(N);
  for(int i=0; i<N; i++){
    data2[i]=data1[i];
  }
  sort(data2.begin(),data2.end());
  
  int mi = data2[(N-1)/2];
  int ma = data2[N/2];
  
  for(int i=0; i<N; i++){
    if(data1[i]<=mi){
      cout << ma << endl;
    }
    else cout << mi << endl;
  }
}