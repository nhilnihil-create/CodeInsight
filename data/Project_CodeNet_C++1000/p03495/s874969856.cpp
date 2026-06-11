#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    vector<int> a(200000);
    int nums = 0;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        a.at(num-1)++;
    }
    
    sort(a.begin(), a.end());
    for (int i=0; i<a.size(); i++) {
        if (a.at(i) != 0) nums++;
    }
    int index = 0;
    int ans = 0;
    while (nums > k) {
    if (a.at(index) == 0) {
        index++;
        continue;
    }
      nums--;
      ans += a.at(index);
      index++;
    }
    
    cout << ans << endl;
    
    
    
    
}
