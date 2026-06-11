// Code for C - Snuke Festival
#include <bits/stdc++.h>
using namespace std;


#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,x,y) for (int i = x; i < y; i++)

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  vector<int> B(N);
  vector<int> C(N);

  REP(i,N) {
    cin >> A[i];
  }

  REP(i,N) {
    cin >> B[i];
  }

  REP(i,N) {
    cin >> C[i];
  }

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  sort(C.begin(), C.end());

  long long int total = 0;
  REP(i,N) {
    int b = B[i];

    int a_count;
    {
      int left = -1;
      int right = N;
      while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if ( A[mid] < b ) {
          right = mid;
        } else {
          left = mid;
        }
      }

      a_count = N - right;
    }

    int c_count;
    {
      int left = -1;
      int right = N;
      while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if ( C[mid] > b ) {
          right = mid;
        } else {
          left = mid;
        }
      }

      c_count = N - right;
    }

    total += (long long)a_count * c_count;
  }

	cout << total << endl;
	return 0;
}
