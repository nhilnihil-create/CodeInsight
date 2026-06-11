#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long>data(n);
  for(int i = 0;i < n;i++){
    cin >> data[i];
  }
  sort(data.begin(),data.end());
  for(long long i = data[1];i > 0;i--){
    int c = 0;
    for(int j = 0;j < n;j++){
      if(data[j]%i != 0) c++;
      if(c == 2) break;
    }
    if(c < 2){
      cout << i << endl;
      return 0;
    }
  }
}
