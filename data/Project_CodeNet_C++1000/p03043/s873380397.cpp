#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int N, K;

int main(){
  cin >> N >> K;

  double prob = 0;

  for( int i=1; i<=N; i++){
    int p = i;
    double prob_i= 1; 
    while( p < K ){
      p *= 2;
      prob_i /= 2;
    }
  prob += (prob_i / N);
  }

  cout << fixed << setprecision(10);
  cout << prob<< endl;
}
