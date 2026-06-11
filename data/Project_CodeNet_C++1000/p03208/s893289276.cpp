#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,k,i;
    cin >> n >> k;
    vector<int> h(n);
    for(i=0;i<n;i++){
        cin>>h[i];
    }
    sort(h.begin(),h.end());
    int ans = 1e9;
    for(int i=0; i<=h.size()-k; i++){
        ans = min(h[i+k-1]-h[i],ans);

    }
    cout<<ans;
    return 0;
}
