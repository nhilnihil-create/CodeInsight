#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

void extGCD(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
    }else{
      long long q = b/a;
      long long r = b%a;

      long long s;
      long long t;
      extGCD(r, a, s, t); // 再帰的に解く

      x = t - q * s;
      y = s;
    }
}

// 負の数にも対応した mod (a = -11 とかでも OK)
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}


int main()
{
  long long N;
  cin >> N;
  long long A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  long long inv[N]; //逆元
  long long p = 1000000007LL;
  long long sum[N+1] = {}; //累積和

  for(int i=0;i<N;i++){
    inv[i] = modinv(i+1,p);
    sum[i+1] = sum[i] + inv[i];
    if(sum[i+1] > p){
      sum[i+1] -= p;
    }
  }

  long long prob[N] = {}; //P(i,j)をiに関して総和をとったもの
  long long result = 0;
  for(int j=0;j<N;j++){
    prob[j] = sum[j+1];
    prob[j] += sum[N-j];
    prob[j] -= 1;
    if(prob[j] > p){
      prob[j] -= p;
    }else if(prob[j] < 0){
      prob[j] += p;
    }

    result += prob[j]*A[j];
    result %= p;
  }

  for(int j=0;j<N;j++){
    result *= (j+1);
    result %= p;
  }

  cout << result << "\n";
	return 0;
}
