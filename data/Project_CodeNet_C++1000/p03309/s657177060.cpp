#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FOR(x,y) for(int i=x; i<y; ++i)
#define FORR(x,y) for(int i=y-1; i>=x; i--)

using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> arr(n),b(n);
    FOR(0,n){
        cin >> arr[i];
        b[i] = arr[i] - (i+1);
    }
    
    
    sort(b.begin(),b.end());
    long long s = b[n/2];
    long long sumS = 0;
    
    FOR(0,n){
        sumS += abs(arr[i] - (s + i + 1));
    }
    cout << sumS << endl;
  return 0;
}
