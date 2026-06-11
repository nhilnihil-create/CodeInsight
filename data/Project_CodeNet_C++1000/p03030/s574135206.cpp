#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<string, int>> rest(n);
    map<int, int> restNum;
    for(int i=0;i<n;i++) cin >> rest[i].first >> rest[i].second;
    for(int i=0;i<n;i++) restNum[rest[i].second] = i+1;
    sort(rest.begin(), rest.end());
    for(int i=1;i<n;i++){
      while(rest[i].first == rest[i-1].first && rest[i].second > rest[i-1].second){
        pair<string, int> tmp;
        tmp = rest[i-1];
        rest[i-1] = rest[i];
        rest[i] = tmp;
        i--;
      }
    }
    for(int i=0;i<n;i++) cout << restNum[rest[i].second] << endl;
    return 0;
}