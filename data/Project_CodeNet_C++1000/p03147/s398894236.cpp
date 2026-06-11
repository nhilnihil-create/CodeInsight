#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    vector<int> cur(n, 0);
    for(; ; ans++){
        int left = 0;
        for(;left < n; left++){
            if(cur[left] < h[left]) break;
        }
        if(left == n) break;
        int right = left;
        for(;right < n; right++){
            if(cur[right] >= h[right]) break;
        }
        for(int i = left; i < right; i++) cur[i]++;
    }

    cout << ans << endl;
    return 0;
}