#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define mod 1000000007
typedef long long ll;
using namespace std;


ll A[1005],B[1005],C[1005],AB[3005];

int main(){
    ll X,Y,Z,K; cin >> X >> Y >> Z >> K;
    for(int i=0;i<X;i++) cin >> A[i];
    for(int i=0;i<Y;i++) cin >> B[i];
    for(int i=0;i<Z;i++) cin >> C[i];

    vector<ll> v;
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            v.push_back(A[i]+B[j]);
        }
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<min(X*Y,K);i++) AB[i] = v[i];

    vector<ll> ans;
    for(int i=0;i<min(X*Y,K);i++){
        for(int j=0;j<Z;j++){
            ans.push_back(AB[i]+C[j]); 
        }
    }
    sort(ans.rbegin(),ans.rend());

    for(int i=0;i<K;i++) cout << ans[i] << "\n";

    return 0;
}