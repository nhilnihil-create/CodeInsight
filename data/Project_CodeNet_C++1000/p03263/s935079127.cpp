#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll H, W,tmp=0, A[500][500];
vector<pair<ll, ll>>  ans1, ans2;

signed main(){
    cin >> H >> W;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            cin >> A[j][i];
        }
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            if(A[j][i]%2==1&&j!=W-1) {
                ans1.push_back(make_pair(j+1, i+1));
                ans2.push_back(make_pair(j+2, i+1));
                A[j][i]--;
                A[j+1][i]++;
            }
        }
        if(i!=H-1) {
            if(A[W-1][i]%2==1) {
                ans1.push_back(make_pair(W, i+1));
                ans2.push_back(make_pair(W, i+2));
                A[W-1][i]--;
                A[W-1][i+1]++;
            }
        }
    }
    cout << ans1.size() << endl;
    for(int i=0;i<ans1.size();i++) {
        cout << ans1[i].second << " " << ans1[i].first << " " << ans2[i].second << " " << ans2[i].first << endl; 
    }
    return 0;
}