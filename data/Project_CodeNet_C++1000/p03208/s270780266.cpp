#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h.at(i);
    }
    sort(h.begin(), h.end());
    int ans = pow(10, 9);
    for(int i=0; i<n-k+1;i++){
        int dif;
        dif = h.at(i+k-1) -h.at(i);
        ans = min(ans, dif);
    }
    cout << ans << endl;
}