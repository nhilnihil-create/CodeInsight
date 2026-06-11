#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    map<int, int> dict;

    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        for (int j=0; j<k; j++){
            int temp;
            cin >> temp;
            dict[temp]++;
        }
    }

    int ans = 0;
    for (auto p: dict){
        auto value = p.second;

        if (value == n){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}