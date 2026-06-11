#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FOR(x,y) for(int i=x; i<y; ++i)
#define FORR(x,y) for(int i=y-1; i>=x; i--)

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    FOR(0,n){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    cout << arr[n-1] - arr[0] << endl;
  return 0;
}