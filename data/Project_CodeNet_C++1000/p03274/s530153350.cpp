#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> memo0(1, 0), memo1(1, 0);
    {
        int pstart = 0;
        for(; a[pstart] < 0; pstart++);
        for(int i = 0; i+pstart < n; i++) memo1.push_back(a[i+pstart]);
        for(int i = 1; pstart-i >= 0; i++) memo0.push_back(-a[pstart-i]);
    }

    int ans = 1001001001;
    for(int i = 0; i <= k; i++){
        if(i < memo1.size() && k-i < memo0.size()){
            if(ans > memo1[i]*2 + memo0[k-i]) ans = memo1[i]*2 + memo0[k-i];
            if(ans > memo1[i] + memo0[k-i]*2) ans = memo1[i] + memo0[k-i]*2;
        }
    }

    cout << ans << endl;
    return 0;
}