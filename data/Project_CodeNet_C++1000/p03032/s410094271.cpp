#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int r=min(n,k);
    int ans=0;
    for(int a = 0; a <= r; a++) {
        for(int b = 0; a+b <= r ; b++) {
            if(a==0 && b==0) continue;
            int val=0;
            vector<int> tmp;
            for(int i = 0; i < a; i++) {
                val+=v[i];
                tmp.emplace_back(v[i]);
            }
            for(int i = 0; i < b; i++) {
                val+=v[n-1-i];
                tmp.emplace_back(v[n-1-i]);
            }

            for(int i = 0; i < tmp.size(); i++) {
                cerr << tmp[i] << " ,";
            }
            cerr << "\n";

            sort(tmp.begin(),tmp.end());

            int idx=0;
            int lim=min(k-a-b,a+b);

            while(tmp[idx]<0) {
                if(idx>=lim) break;
                val=val-tmp[idx];
                idx++;
                if(idx>=lim) break;
            }
            ans=max(ans,val);
        }
    }
    cout << ans << "\n";

    return 0;
}