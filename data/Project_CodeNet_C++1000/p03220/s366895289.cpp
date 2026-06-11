#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int N,T,A;
    cin>>N>>T>>A;
    double min = 100000;
    int index;
    rep(i, N){
        int H;
        cin>>H;
        double t = T-H*0.006;
        if(min > abs(A-t)){
            min = abs(A-t);
            index = i+1;
        }
    }

    cout << index << endl;
}
