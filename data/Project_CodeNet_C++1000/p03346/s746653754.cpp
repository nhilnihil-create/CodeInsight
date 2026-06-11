# include <bits/stdc++.h>
using namespace std;

/*
  Ide : cari longest subsequence yang isinya x, x+1, ..., x+K-1
  N-K elemen selain subsequence ini bisa dipindahin ke belakang atau depan

  Misal : 
  6 3 1 2 7 4 8 5
  ^       ^   ^
  Pindahin 5 ke depan, 4 ke depan, 3 ke depan, 2 ke depan, 1 ke depan    
*/

int main(){

  int n;
  cin >> n;
  
  int p[n+5], pos[n+5];
  for(int i=1; i<=n; i++){
    cin >> p[i];
    pos[p[i]] = i;
  }

  int len = 1, maxlen = 1;
  for(int i=1; i<n; i++){
    if(pos[i] < pos[i+1]){
      len++;
      maxlen = max(maxlen, len);
    }
    else len = 1;
  }

  cout << n - maxlen << endl;
  return 0;
}