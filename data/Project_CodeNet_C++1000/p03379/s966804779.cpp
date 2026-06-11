#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        arr.emplace_back(temp, i);
    }
    sort(arr.begin(), arr.end());
    int ans[arr.size()];
    for(int i = 0; i < n; i++){
        if(i < n / 2){
            ans[arr[i].second] = arr[n / 2].first;
        } else {
            ans[arr[i].second] = arr[n / 2 - 1].first;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}