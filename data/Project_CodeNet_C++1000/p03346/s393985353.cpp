#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n; cin >> n;
    vector<int> a(n), ind(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--; ind[a[i]] = i;
    }

    int cnt = 1;
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j < n && ind[j] > ind[j - 1]){
            j++;
        }
        cnt = max(j - i + 1, cnt);
        i = j;
    }
    cout << n - cnt << endl;
}