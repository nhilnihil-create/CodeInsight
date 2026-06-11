#include <iostream>
#include <map>
using namespace std;

map<long long, int> cnt;

int main() {
      ios_base::sync_with_stdio(false); 
      cin.tie(NULL); 
      cout.tie(NULL);

      int N;
      cin >> N;

      long long ans = 0, sum = 0;
      long long num;
      cnt[0] = 1;
      for(int i=0; i<N; i++) {
            cin >> num;
            sum += num;
            ans += cnt[sum];
            cnt[sum]++;
      }
      cout << ans << endl;
      return 0;
}