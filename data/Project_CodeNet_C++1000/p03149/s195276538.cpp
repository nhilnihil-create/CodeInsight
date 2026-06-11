#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];

int main(){
    vector<int> N(4); collect(N, 4);
    sort(all(N));
    int ans[4] = {1,4,7,9};
    bool makeable = true;
    rep(i,4) if(N[i] != ans[i]) makeable = false;
    cout << (makeable ? "YES" : "NO") << endl;
}