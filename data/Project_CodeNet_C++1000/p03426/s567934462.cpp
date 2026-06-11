#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,d;
    cin >> h >> w >> d;
    int a[h*w];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            int tmp;
            cin >> tmp;
            tmp--;
            a[tmp]=i*w+j;
        }
    }
    int q;
    cin >> q;
    int l[q],r[q];
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    vector<int> cost(h*w+5,0);
    for(int i = d; i <= h*w; i++) {
        int pc=a[i-d]%w;
        int pr=a[i-d]/w;
        int nc=a[i]%w;
        int nr=a[i]/w;
        int tc=(abs(pc-nc)+abs(pr-nr));
        cost[i]=cost[i-d]+tc;
    }

    for(int i = 0; i < q; i++) {
        cout << cost[r[i]]-cost[l[i]] << "\n";
    }

    return 0;
}