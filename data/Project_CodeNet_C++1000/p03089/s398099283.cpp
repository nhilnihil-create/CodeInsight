#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 100;

ll N, ans=0, tmp=0;
vector<ll> A, B, C;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        tmp = max(tmp, a);
        A.push_back(a);
    }
    if(tmp>N) {
        cout << -1 << endl;
        return 0;
    }
    reverse(A.begin(), A.end());
    for(int i=0;i<tmp;i++) {
        B.push_back(A.back());
        A.pop_back();
    }
    while(C.size()!=N) {
        ll flag=0;
        for(int i=tmp-1;i>=0;i--) {            
            if(B[i]==i+1&&flag==0) {
                for(int j=i;j<tmp-1;j++) {
                    B[j] = B[j+1];
                }
                if(!A.empty()) {
                    B[tmp-1] = A.back();
                    A.pop_back();
                }
                else {
                    B[tmp-1] = 0;
                }
                C.push_back(i+1);
                flag=1;
            }
        }
        if(!flag) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=C.size()-1;i>=0;i--) {
        cout << C[i] << endl;
    }
    return 0;
}