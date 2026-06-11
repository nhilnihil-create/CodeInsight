#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N),OrigiNal(N);
    for(int i=0;i<N;i++){
        cin >> X[i];
        OrigiNal[i] = X[i]; 
    }
    sort(X.begin(),X.end());
    for(int i=0;i<N;i++){
        int t= lower_bound(X.begin(),X.end(),OrigiNal[i]) - X.begin();
        // cerr <<"t="<<t << endl;
        if(t<(N/2)){
            cout << X[(N/2)] << endl;
        }else{
            cout << X[(N/2)-1] <<endl;
        }
    }


    return 0;
}