#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> ans{a + c, a + d, b + c, b + d};
    sort(ans.begin(), ans.end());
    cout << ans.at(0) << endl;
}