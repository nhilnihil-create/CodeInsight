#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

// aとbの最大公約数
long long gcd(long long a, long long b){
  if (a%b == 0)
    return(b);
  else
    return(gcd(b, a%b));
}


int main(){
  long long N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  // 入力終了

  // NとMの最大公約数
  long long L;
  L = N*M/gcd(N, M);

  long long n = L/N, m = L/M;

  long long MAX = max(N, M);
  long long min_nm = min(n, m);
  long long max_nm = max(n, m);
  
  string longstr = S;
  string shortstr = S;
  if(N < M)
    longstr = T;
  else
    shortstr = T;
  
  // SとTのうち，文字列長が長い方を見る
  for(long long i=0; i<MAX; i++){
    // 文字列Xの中で何文字目か
    long long l = i*min_nm;
    
    // 文字列Sのi文字目(文字列Xのl文字目)がTに関連する場合のみ見ればOK
    if( l % max_nm == 0)
      // 文字列Sのi文字目に対応するSとTの
      // それぞれの文字が一致しなければNG
      if(longstr[i] != shortstr[l/max_nm]){
	cout << -1 << endl;
	return 0;
      }
  }
  
  // 解答
  cout << L << endl;

  return 0;
}
