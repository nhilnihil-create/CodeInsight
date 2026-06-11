#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(3, 0);
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x <= a) ans[0]++;
        else if (x <= b) ans[1]++;
        else ans[2]++;
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
}