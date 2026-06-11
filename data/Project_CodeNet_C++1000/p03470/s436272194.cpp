#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> d;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        d.push(tmp);
    }

    int ans = 1;
    for(int i = 1; i < n; i++) {
        int tmp = d.top();
        d.pop();

        if(tmp != d.top()) {
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}