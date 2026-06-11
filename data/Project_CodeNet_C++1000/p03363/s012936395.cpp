#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int lli;

int main(){
    int n;
    cin >> n;
    vector<lli> a(n+1, 0);
    for(int i=0; i<n; i++){
        cin >> a[i+1];
    }
    for(int i=0; i<n; i++){
        a[i+1] += a[i];
    }
    lli ans = 0;
    map<lli, lli> nums;
    for(int i=0; i<n+1; i++){
        ans += nums[a[i]];
        nums[a[i]]++;
    }
    cout << ans << endl;
    return 0;
}