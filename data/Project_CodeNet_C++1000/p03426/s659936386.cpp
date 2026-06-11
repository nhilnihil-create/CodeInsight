#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 90001;
pair<int, int> mat[MAX];

int main(){
    int h, w, d;
    cin >> h >> w >> d;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int a;
            cin >> a;
            mat[a] = make_pair(i, j);
        }
    }
    vector<ll> sum(h * w + 1, 0);
    for(int i = 1; i <= d; i++){
        int t = i;
        int prex, prey;
        tie(prex, prey) = mat[i];
        while(t <= h * w){
            int x, y;
            tie(x, y) = mat[t];
            if(t != i) sum[t] = sum[t - d] + abs(x - prex) + abs(y - prey);
            prex = x;
            prey = y;
            t += d;
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l] << endl;
    }
    return 0;
}