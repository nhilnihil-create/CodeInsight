#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string>vec(N);
  cin >> vec[0];
  for(int i=1; i<N; i++){
    cin >> vec[i];
    string a = vec[i],b = vec[i-1];
    if(a[0] != b[b.size()-1]){
      cout << "No" << endl;
      return 0;
    }
  }
  sort(vec.begin(),vec.end());
  for(int i=0; i<N-1; i++){
    if(vec[i] == vec[i+1]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
