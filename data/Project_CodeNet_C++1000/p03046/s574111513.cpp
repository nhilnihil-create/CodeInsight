#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class T> ostream& operator<<(ostream& os, const vector<T> arr){ for(int i = 0; i < (int)arr.size(); i++)cout << arr[i] << (i == (int)arr.size() -1 ? "" : " "); return os;}

int main()
{
    int m, k;
    cin >> m >> k;
    int n = 1<<m;
    if(k==0) {
        for(int i = 0; i < n; i++)cout << i << " " << i << " ";
        return 0;
    }
    int ac = 0;
    for(int i = 0; i < n; i++)ac ^= i;
    if(k >= n || ac) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans(n * 2, -1);
    int cur = 0;
    for(int i = 0; i < n; i++, cur++) {
        if(i == k)cur++;
        ans[i] = cur;
        ans[2 * n- i - 2] = cur;
    }
    ans[n - 1] = ans[2 * n - 1] = k;
    cout << ans << endl;
}