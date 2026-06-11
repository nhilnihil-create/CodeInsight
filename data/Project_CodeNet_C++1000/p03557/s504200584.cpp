#include <iostream> 
#include <algorithm>
#include <vector>

using namespace std; 

// It looks like this bullshit manual code doesn't work on some obscure cases

// Returns the exclusive lower bound index in sorted array 
int binary_search(vector<long long>& arr, long long val) {
  int lo = -1; // Lower bound exclusive
  int hi = arr.size(); // Upper search bound 
  
  while (hi - lo > 1) {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] <= val) lo = mid; 
    else hi = mid; 
  }
  return hi; // if it doesn't exist it returns arr.size() which is fine
}

// int main() {
//   int N; cin >> N;
//   vector<int> A(N);
//   for (int i = 0; i < N; i++) {
//     cin >> A[i];
//   }
//   vector<int> B(N);
//   for (int j = 0; j < N; j++) {
//     cin >> B[j];
//   }
//   vector<int> C(N);
//   for (int k = 0; k < N; k++) {
//     cin >> C[k];
//   }

//   sort(A.begin(), A.end());
//   sort(B.begin(), B.end());
//   sort(C.begin(), C.end());

//   long long ans = 0;

//   // O(NlogN)
//   int b_scores_cumulative[N+1];
//   b_scores_cumulative[N] = 0;
//   for (int i = N - 1; i >= 0; i--) {
//     int index = binary_search(C, B[i]);
//     b_scores_cumulative[i] = b_scores_cumulative[i+1] + N - index;
//   }

//   // O(NlogN)
//   for (int j = N - 1; j >= 0; j--) {
//     int index = binary_search(B, A[j]);
//     ans += b_scores_cumulative[index];
//   }

//   cout << ans << endl;
// }

// Hint instead of thinking A -> B and B -> C, think B -> A and B -> C
// Instead of taking time to build lower and upper bound searchers just use std::lower_bound and std::upper_bound 
// Moral of the lesson: just use stl whenever possible... and watch out for types 
int main() {
  int N; cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<long long> B(N);
  for (int j = 0; j < N; j++) {
    cin >> B[j];
  }
  vector<long long> C(N);
  for (int k = 0; k < N; k++) {
    cin >> C[k];
  }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  long long ans = 0;
  for (int j = 0; j < N; j++) {
    auto i = lower_bound(A.begin(), A.end(), B[j]); // Everything to the left of the inclusive lower bound -> exclusive
    long long a_score = i - A.begin(); // Iterator differences (and indices) can be taken from subtraction
    auto k = upper_bound(C.begin(), C.end(), B[j]); // Everything to the right of the exclusive lower bound -> inclusive
    long long c_score = C.end() - k;
    ans += a_score * c_score; // Lol this is the exact thing I did except with my own func... which once again is verified 
  }

  cout << ans << endl;
}