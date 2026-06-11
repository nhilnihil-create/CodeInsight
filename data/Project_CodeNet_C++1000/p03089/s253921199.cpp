#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 105;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> ans;

    while (n > 0) {
        int x = -1;
        for (int i = n; i > 0; i--) {
            if (a[i] == i) {
                x = i;
                break;
            }
        }
        if (x == -1) {
            cout << -1;
            return 0;
        }
        for (int i = x; i < n; i++) {
            swap(a[i], a[i + 1]);
        }
        n--;
        ans.push_back(x);
    }

    reverse(all(ans));
    
    for (int x : ans)
        cout << x << "\n";



 
    return 0;
}