#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans = 0;
    cin >> n;
    vector<int> price(n);
    vector<int> cost(n);
    vector<int> difference(n);
    for (int i = 0; i < n; i++){
        cin >> price.at(i);
    }
    for (int i = 0; i < n; i++){
        cin >> cost.at(i);
        if(price.at(i) - cost.at(i) > 0)
            ans += price.at(i) - cost.at(i);
    }
    cout << ans << endl;
}