#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> candy1(n);
    vector<int> candy2(n);
    for(int i=0; i<n; i++){
        cin >> candy1.at(i);
    } 
    for(int i=0; i<n; i++){
        cin >> candy2.at(i);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        int cnt=0;
        for(int j=0; j<i; j++){
            cnt += candy1.at(j);
            //cout << cnt << " ";
        }
        for(int j=i-1; j<n; j++){
            cnt += candy2.at(j);
            //cout << cnt << " ";
        }
        //cout << cnt << endl;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}