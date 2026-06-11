#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define SORT(s) sort((s).begin(),(s).end())

int main(){
    int N; cin >> N;
    vector<ll> L(N);
    REP(i,N){cin >> L[i];}

    SORT(L);
    ll sum_L = 0;
    REP(i,N-1){sum_L += L[i];}
    if(sum_L > L[N-1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
