#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(int i=0; i < (int)(n); i++)

int main(){
    int N;
    cin >> N;

    vector<int> A(N),B(N),C(N);
    rep(i,N) cin >> A.at(i);
    rep(i,N) cin >> B.at(i);
    rep(i,N) cin >> C.at(i);

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());

    ll num = 0;
    for(auto itr=B.begin(); itr!=B.end(); itr++){
        ll a_num = 0;
        ll c_num = 0;
        auto itr_a = lower_bound(A.begin(), A.end(), *itr);
        auto itr_c = upper_bound(C.begin(), C.end(), *itr);
        a_num = itr_a - A.begin();
        if(itr_c != C.end()) c_num = C.end() - itr_c;
        num += a_num*c_num;

    }
    cout << num << endl;
    return 0;

} 
