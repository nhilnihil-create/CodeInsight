#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



long long xxor2(long long N, long long K, long long a[]) {
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
      A[i] = a[i];
    }
        
    long long res = 0;
    for (int d = 60; d >= -1; --d) { // d = -1 は X = K の場合
        if (d != -1 && !(K & (1LL<<d))) continue;
	// go if k = 1
        
        long long tmp = 0;
        for (int e = 60; e >= 0; --e) {
            long long mask = 1LL<<e;
            long long num = 0;
            for (int i = 0; i < N; ++i) if (A[i] & mask) ++num;
            
            if (e > d) {
                if (K & mask) tmp += mask * (N - num);
                else tmp += mask * num;
            }
            else if (e == d) {
                tmp += mask * num;
            }
            else {
                tmp += mask * max(num,  N - num);
            }
        }
        res = max(res, tmp);
    }
    return res;
}

int max_bit(long long k) {
  int counter = 0;
  while(k !=0) {
    k = k >> 1;
    counter++;
  }
  return counter;
}

long long xxor(long long n, long long k, long long a[]) {
  int k_bit_peek = max_bit(k);

  int begin = k_bit_peek;
  for(long long i=0;i<n;i++) {
    begin = max(begin, max_bit(a[i]));
  }
  // all zero
  if(begin ==0) {
    return 0;
  }
  //cout << "max_bit: " << begin << endl;
  
  long long res = 0;
  for(int i=begin; i!=-1; i--) {
    if(i != 0 && ( (k & (1LL << (i-1))) == 0)) {
      continue;
    }
    long long temp_ans = 0;
    for(int j=begin; j!=0; j--) {
      long long num_of_one = 0;
      long long flag = 1LL << (j-1);
      for(long long k = 0;k<n;k++) {
	if (a[k] & flag) {
	  num_of_one++;
	}
      }
      if(j>i) {
	if(k & flag) {
	  temp_ans += flag * (n - num_of_one);
	} else {
	  temp_ans += flag * num_of_one;
	}
      } else if (j==i) {
	//cout << "j==i " << flag * num_of_one << endl;
	temp_ans += flag * num_of_one;
      } else {
	//cout << "j<i " << flag * max(num_of_one, n-num_of_one) << endl;
	temp_ans += flag * max(num_of_one, n-num_of_one);
      }
    }
    // cout << "best: " << res << " current: " << temp_ans << " at " << i << endl;
    res = max(res, temp_ans);
  }
  return res;
}

int main() {
  long long n, k;
  cin >> n;
  cin >> k;
  long long a[n];
  for(long long i=0;i<n;i++) {
    cin >> a[i]; 
  }
  cout << xxor(n, k, a);
}