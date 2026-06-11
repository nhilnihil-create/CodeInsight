#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

ll arr[1000005];

void freq(ll N, string S, int curr) {
      for(ll i=0; i<N; i++) {
            curr = (int)S[i]; // cast current letter of string S to ASCII
            arr[curr]++;
      }
}

ll multiply(ll N, string S, ll ans) {

      ll temp = pow(10,9) + 7;
      for(int i=(int)'a'; i<=(int)'z'; i++) {
            ans *= (arr[i]+1);
            ans = ans % temp; 
      }
      return ans; 
}

void solution(ll N, string S) {
      freq(N, S, 0);
      ll res = multiply(N, S, 1) - 1;
      cout << res << endl; 
}


int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);

      ll N;
      string S;
      cin >> N >> S;

      solution(N, S);
}
