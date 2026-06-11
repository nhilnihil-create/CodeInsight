#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> P(N);
    ll easy = 0, med = 0, hard = 0;
    Rep (i, N) {
        cin >> P[i];
        if (P[i] <= A) easy++;
        else if (P[i] <= B) med++;
        else hard++;
    }

    cout << min({easy, med, hard}) << "\n";


}