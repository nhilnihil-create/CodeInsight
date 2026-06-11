#include"bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin >> a[i];
    vector<long long> acc(n+1);
    for (int i = 0; i<n+1; i++) acc[i] = 0;
    for (int i = 0; i<n; i++) acc[i+1] = acc[i] + a[i];
    //一個目の右端
    int left = 1;
    //三個目の右端
    int right = 3;
    long long ans = 1'000'000'000'000'000;
    //二個目の右端を全探索
    for (int i = 2; i<n-1; i++){
        while (abs(2*acc[left+1] - acc[i]) < abs(2*acc[left] - acc[i])) left++;
        while (abs(2*acc[right+1] - acc[i] - acc.back()) < abs(2*acc[right] - acc[i] - acc.back())) right++;
        ans = min(ans, max({acc[left], acc[i] - acc[left], acc[right] - acc[i], acc.back() - acc[right]}) - min({acc[left], acc[i] - acc[left], acc[right] - acc[i], acc.back() - acc[right]}));
    }
    
    cout << ans << endl;
}

