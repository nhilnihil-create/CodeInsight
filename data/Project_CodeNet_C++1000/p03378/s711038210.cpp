#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> a(M);
  for(int i = 0; i<M; i++){
    cin >> a.at(i);
  }
  int count_a;
  int count_b;
  for(int i = 0; i<M; i++){
    if(a.at(i)<X){
      count_a++;
    }
    else{
      count_b++;
    }
  }
  cout << min(count_a,count_b) << endl;
}
