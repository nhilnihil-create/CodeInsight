#include <bits/stdc++.h>
#define N 100000
using namespace std;
vector<bool> SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    vector<bool> prime(n+1,true);
    prime[0] = false;
    prime[1] = false;
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    return prime;
} 
int main() {
  vector<bool> prime = SieveOfEratosthenes(N);
  int x[N+1], Q, l, r;
  x[0] = 0;
  for (int i = 1; i <= N; i++) {
    x[i] = i%2 && prime[i] && prime[(i+1)/2];
  }
  for (int i = 1; i <= N; i++) {
    x[i] += x[i-1];
  }
  for (cin >> Q; Q; Q--) {
    cin >> l >> r;
    cout << x[r]-x[l-1] << endl;
  }
}