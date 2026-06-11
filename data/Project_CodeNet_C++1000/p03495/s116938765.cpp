#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<int>cnt(n,1);
    int x=0;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            cnt[x]++;
        }
        else x++;
    }
    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=cnt[i];
    }
    if(n-ans<0){
        cout << 0 << endl;
        return 0;
    } 
    cout << n-ans << endl;
}