# include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;
  vector <int> m(N);
  for (int i=0; i<N; i++){
    cin >> m[i];
  }
  int sum=0;
  for (int i=0; i<N; i++){
    sum+=m[i];
  }
  int count=N;
  sort(m.begin(),m.end());
  while (1){
    sum+=m.at(0);
    count++;
    if (sum>X){
      break;
    }
  }
  cout << count-1 << endl;
}

