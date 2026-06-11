#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    int cnt = 0;
    for(auto x : mp){
        if(x.first < x.second){
            cnt += x.second - x.first;
        } else if(x.first > x.second){
            cnt += x.second;
        }
    }
    cout << cnt << endl;
    return 0;
}