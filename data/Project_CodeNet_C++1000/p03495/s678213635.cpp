#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    set<ll> ss;
    map<ll,ll> mpa;

    for(ll i = 0;i < N;i++){
        cin >> A.at(i);
        ss.insert(A.at(i));
    }

    for(auto x:ss){
        mpa[x] = 0;
    }

    for(int i = 0;i < N;i++){
        mpa[A.at(i)]++;
    }

    ll ss_size = ss.size();
    vector<ll> B(ss_size);

    ll j = 0;
    for(auto i:ss){
        B.at(j) = mpa[i];
        j++;
    }
    
    sort(B.begin(),B.end());

    ll goukei = 0;

    for(ll i = 0;i < ss_size - K;i++)
        goukei += B.at(i);

    cout << goukei << endl;


    

}