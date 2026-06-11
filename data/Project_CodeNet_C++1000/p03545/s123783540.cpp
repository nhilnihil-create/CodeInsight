#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vl = vector<ll>; using vvl = vector<vl>;
using vp = vector<pair<int,int>>;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
const ll INF = 9223372036854775807;

int main() {
    int n;cin >> n;
    vector<int> in(4);
    rep(i,4){
        in[3-i]=n % 10;
        n /= 10;
    }
    rep(i,(1 << 3)) {
        bitset<3> op(i);
        int sum = in[0];
        rep(j,3){
            if(op.test(j)) sum += in[j + 1];
            if(!op.test(j)) sum -= in[j + 1];
        }
        if(sum == 7) {
            vector<char> opv(0);
            rep(j,3) {
                if(op.test(j)) opv.push_back('+');
                if(!op.test(j)) opv.push_back('-');
            }
            cout << in[0] << opv[0] << in[1] << opv[1] << in[2] << opv[2] << in[3] << "=7" << endl;
            break;
        }
    }
}