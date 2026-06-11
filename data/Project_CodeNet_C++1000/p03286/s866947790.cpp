#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N;
    if(N==0) {
        cout << 0 << endl;
        return 0;
    }
    while(N!=1) {
        if(N%2==0) {
            N = N/2;
            N = -N;
            A.push_back(0);
        }
        else {
            N = (N-1)/2;
            N = -N;
            A.push_back(1);
        }
        //cout << N << endl;
    }
    A.push_back(1);
    while(!A.empty()) {
        cout << A.back();
        A.pop_back();
    }

    return 0;
}