#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
using ll = long long;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sum(n+1);
    for (int i=1;i<n+1;i++){
        if(s.at(i-1)=='E')
            sum.at(i) = sum.at(i-1)+1;
        else
            sum.at(i) = sum.at(i-1);
    }
    int ans = INF;
    // (0)W(0)E(1)E(2)W(2)W(2)
    for (int i=0;i<n+1;i++){
        //左のWの数
        // cout << i-sum.at(i) << endl;
        // cout << sum.at(n)-sum.at(i);
        ans = min (ans,i+sum.at(n)-2*sum.at(i));
    }
    cout << ans << endl;
    return 0;
}