#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000001;
constexpr ll INF= 1e18;
constexpr ll MOD = 998244353;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    if(S.at(0) == '0' || S.at(N - 1) == '1' || S.at(N - 2) == '0') {
        cout << -1 << endl;
    }
    else {
        bool ret = true;
        vector<int> cnt;
        for(int i = 0;i < N / 2;i++) {
            if(S.at(i) != S.at(N - 2 - i)) {
                ret = false;
            }
            else if(S.at(i) == '1' && i != 0) {
                cnt.push_back(i + 1);
            }
        }
        if(ret == false) {
            cout << -1 << endl;
        }
        else {
            reverse(cnt.begin(),cnt.end());
            cnt.push_back(1);
            vector<P> ret;
            ret.push_back(P(1,2));
            int cnt2 = 2;
            int cnt3 = 3;
            for(int i = 0;i < cnt.size() - 1;i++) {
                int cnt4 = cnt.at(i) - cnt.at(i + 1);
                for(int j = 0;j < cnt4;j++) {
                    ret.push_back(P(cnt2,cnt3));
                    cnt3++;
                }
                cnt2 = cnt3 - 1;
            }
            for(int i = cnt.at(0) + 2;i <= N;i++) {
                ret.push_back(P(1,i));
            }
            for(int i = 0;i < ret.size();i++) {
                cout << ret.at(i).first << " " << ret.at(i).second << endl;
            }
        }
    }
}