#include <iostream>
#include <vector>

long f(long n){
      long ans = 0;
      while(n % 2 == 0){
            ans++;
            n /= 2;
      }
      return ans;
}
using namespace std;
int main(void){
    int n;
    cin >> n;
    long ans = 0;
    vector<long> a(n);
    for(int i = 0;i < n;i++){
          cin >> a[i];
          ans += f(a[i]);
    }
    cout << ans << endl;
}
