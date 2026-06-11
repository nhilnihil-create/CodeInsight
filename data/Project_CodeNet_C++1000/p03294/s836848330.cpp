#include <iostream>
#include <vector>
using namespace std;
int main(void){
    long n;
    cin >> n;
    vector<long> a(n);
    long ans = 0;
    for(long i = 0;i < n;i++){
          cin >> a[i];
          ans += a[i] - 1;
    }
    cout << ans << endl;
}
