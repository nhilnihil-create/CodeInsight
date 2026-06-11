#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    
    int n; cin >> n;
    vector<int> a(100000, 0), b(100000, 0);
    vector<int> mp;
    ll minas_sum = 0;
    int ans = 0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++){
        int tmp = a[i] - b[i];
        mp.push_back(tmp);
        if(tmp < 0){
            ans++;
            minas_sum += tmp;
        }
    }
    sort(mp.begin(), mp.end());

    for(int i=n-1; i>=0; i--){
        if(minas_sum>=0){
                break;
        }
        if(mp[i] > 0){
            minas_sum += mp[i];
            ans++;
        }else if(mp[i]<=0){
            break;
        }
    }
    if(minas_sum < 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}