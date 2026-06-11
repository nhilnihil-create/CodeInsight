#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll n;
    cin >> n;
    vector<ll> a;
    vector<ll> b;
    map<ll,ll> A;
    map<ll,ll> B;
    rep(i,n){
        ll v;
        cin >> v;
        if(i%2==0){
            if(A.count(v)) A[v]++;
            else{
                A.emplace(v,1);
                a.push_back(v);
            }
        }else{
            if(B.count(v)) B[v]++;
            else{
                B.emplace(v,1);
                b.push_back(v);
            }
        }
    }
    ll out = 0;
    ll c = a.size();
    ll d = b.size();
    ll ma = 0;
    ll ma2 = 0;
    ll maa = 0;
    ll mb = 0;
    ll mb2 = 0;
    ll mbb = 0;
    rep(i,c){
        if(A[a[i]]>=ma){
            if(ma>ma2) ma2 = ma;
            ma = A[a[i]];
            maa = a[i];
        }else if(A[a[i]]>ma2) ma2 = A[a[i]];
    }
    rep(i,d){
        if(B[b[i]]>=mb){
            if(mb>mb2) mb2 = mb;
            mb = B[b[i]];
            mbb = b[i];
        }else if(B[b[i]]>mb2) mb2 = B[b[i]];
    }
    if(maa!=mbb) out = n-(ma+mb);
    else{
        out = min(n-(ma2+mb),n-(ma+mb2));
    }
    cout << out << endl;
    return 0;
}
