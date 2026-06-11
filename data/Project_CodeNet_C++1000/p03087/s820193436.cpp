#include <iostream>
#include <vector>
using namespace std;

int main(){

  int n;  int q;

  cin >> n;  cin >> q;

  char s[n];
  for(int i = 0; i < n; ++i){
    cin >> s[i];
  }

  vector<int> S(n+1, 0);
  for(int i = 0; i < n; ++i){
    if(i+1 < n && s[i] == 'A' && s[i+1] == 'C'){
      S[i+1] = S[i] + 1;
    }else{
      S[i+1] = S[i];
    }
  }

  for(int i = 0; i < q; ++i){
    int l, r;
    cin >> l >> r;
    --l;
    --r;

    cout << S[r] - S[l] << endl;
  }

}