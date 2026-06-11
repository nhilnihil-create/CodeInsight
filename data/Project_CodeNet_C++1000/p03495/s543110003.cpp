#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main(void){
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        mp[a]++;
    }

    int typs = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<=200000; i++){
        if(mp[i] > 0){
            typs++;
            pq.push(mp[i]);
        }
    }

    int ans = 0;
    while(typs > k){
        typs -= 1;
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}