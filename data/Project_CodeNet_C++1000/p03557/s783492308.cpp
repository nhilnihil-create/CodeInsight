#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <numeric>
 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
string S,T;
vector<ll> A;
vector<ll> B;
vector<ll> C;
ll D[100000];


ll N;
ll ans;

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<N;i++){
        ll b;
        cin >> b;
        B.push_back(b);
    }
    for(int i=0;i<N;i++){
        ll c;
        cin >> c;
        C.push_back(c);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    for(int i=0;i<N;i++){
        D[i] = lower_bound(A.begin(),A.end(),B[i])-A.begin();
        if(i>0){
        D[i]+= D[i-1];
        }
    }
    for(int i=0;i<N;i++){
        ans += D[lower_bound(B.begin(),B.end(),C[i])-B.begin()-1];
    }
    cout << ans << endl;
    
}
