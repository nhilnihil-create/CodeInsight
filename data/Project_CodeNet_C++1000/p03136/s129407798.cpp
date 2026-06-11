#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    int N;
    cin>>N;
    int max = 0;
    int sum = 0;
    rep(i, N){
        int L; cin>>L;
        sum += L;
        max = std::max(max, L);
    }

    if(sum-max > max){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
