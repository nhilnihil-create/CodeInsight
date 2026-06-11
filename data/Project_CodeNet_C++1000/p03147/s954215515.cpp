#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    vector<int>h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        while(h[i]>0){
            for(int j=i;j<n;j++){
                if(h[j]>0) h[j]--;
                else break;
            }
            ans++;
        }
    }
    cout << ans << endl;
}