#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N;
    cin >> N;
    ll Ai;
    vector<ll> A{0};
    for(int i=0;i<N;i++){
        cin >> Ai;
        A.push_back(Ai + A.back());
    }
    ll res = numeric_limits<ll>::max();
    for(int i=2;i<N-1;i++){
        auto itr1 = lower_bound(A.begin(), A.end(), (A[0] + A[i])/2);
        auto itr2 = lower_bound(A.begin(), A.end(), (A[i] + A[N])/2);
        vector<ll> cand1{
            (A[i] - *prev(itr1,0)), (*prev(itr1,0) - A[0]),
            (A[N] - *prev(itr2,0)), (*prev(itr2,0) - A[i]),
        };
        vector<ll> cand2{
            (A[i] - *prev(itr1,0)), (*prev(itr1,0) - A[0]),
            (A[N] - *prev(itr2,1)), (*prev(itr2,1) - A[i]),
        };
        vector<ll> cand3{
            (A[i] - *prev(itr1,1)), (*prev(itr1,1) - A[0]),
            (A[N] - *prev(itr2,0)), (*prev(itr2,0) - A[i]),
        };
        vector<ll> cand4{
            (A[i] - *prev(itr1,1)), (*prev(itr1,1) - A[0]),
            (A[N] - *prev(itr2,1)), (*prev(itr2,1) - A[i]),
        };
        sort(cand1.begin(), cand1.end());
        sort(cand2.begin(), cand2.end());
        sort(cand3.begin(), cand3.end());
        sort(cand4.begin(), cand4.end());
        auto cand = min({
            cand1[3]-cand1[0],
            cand2[3]-cand2[0],
            cand3[3]-cand3[0],
            cand4[3]-cand4[0],
        });
        res = min(res, cand);
    }
    cout<<res<<endl;

    return 0;
}