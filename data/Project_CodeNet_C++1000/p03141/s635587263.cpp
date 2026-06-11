#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1e9;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

int main() {
    int N;
    cin >> N;
    vector<tuple<ll,ll,ll>> vec(N);
    for(int i = 0;i < N;i++) {
        ll A,B;
        cin >> A >> B;
        vec.at(i) = make_tuple(A + B,A,B);
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    ll t = 0;
    ll o = 0;
    for(int i = 0;i < N;i++) {
        if(i % 2 == 0) {
            t += get<1>(vec.at(i));
        }
        else {
            o += get<2>(vec.at(i));
        }
    }
    cout << t - o << endl;
}