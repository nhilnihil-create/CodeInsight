#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;

int main() {
    int N,Z,W; cin>>N>>Z>>W;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    if(N==1){
        cout<<abs(a[0]-W)<<endl;
    }else{
        cout<<max(abs(a[N-1]-W),abs(a[N-2]-a[N-1]));
    }

    return 0;
}
