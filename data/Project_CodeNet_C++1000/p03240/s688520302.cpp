#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;


int main(){
    int n; cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);
    tuple<int, int, int> t = make_tuple(-1,-1,-1);
    rep(i,n){
        cin >> x[i] >> y[i] >> h[i];
        if(h[i]>=1)  t = make_tuple(x[i], y[i], h[i]); 
    }
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            int H = get<2>(t) + abs(get<0>(t) - i) + abs(get<1>(t) - j);
            bool isOK = true;
            rep(k,n){
                int tmp = H - abs(x[k] - i) - abs(y[k] - j);
                tmp = max(tmp, 0);
                if(tmp != h[k])isOK = false;
            }
            if(isOK) cout << i << " " << j << " " << H << endl; 
        }
    }
    return 0;
}