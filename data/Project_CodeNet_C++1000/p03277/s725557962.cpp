#include<bits/stdc++.h>
using namespace std;
const int N = 200000;
int bit[N + 10];
void update(int idx, int val, int lim){
    while(idx <= lim){
        bit[idx] += val;
        idx += idx & -idx;
    }
}
int query(int idx){
    int ans = 0;
    while(idx){
        ans += bit[idx];
        idx -= idx & -idx;
    }
    return ans;
}
bool check(vector<int> a, int x){
    int sum, n = a.size() - 1;
    long long cnt = 0;
    for(int i = 1; i <= n; i++){
        a[i] = (a[i] >= x ? 1 : -1);
    }
    for(int i = 0; i <= 2 * n + 1; i++){
        bit[i] = 0;
    }
    sum = n + 1;
    for(int i = 0; i <= n; i++){
        sum += a[i];
        cnt += query(sum);
        update(sum, 1, 2 * n + 1);
    }
    long long N = 1LL * n * (n + 1) >> 1;
    return (cnt >= N - N / 2);
}
int main(){
    int n, ans = -1;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int low = 1, high = 1e9, mid;
    while(low <= high){
        mid = (low + high) >> 1;
        if(check(a, mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}