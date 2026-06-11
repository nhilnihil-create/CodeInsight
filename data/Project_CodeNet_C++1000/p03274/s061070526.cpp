#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main(){
    int N, K, j;    cin >> N >> K;
    ll ans = 10000000000000000;
    ll ans1;
    vector<ll> v(N);
    j = 0;
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    for(int i=0; i<=N-K; i++){
        if(v[i] * v[i+K-1] < 0){
            ans1 = abs(v[i]) + v[i+K-1] + min(abs(v[i]),v[i+K-1]);
        }else if(v[i] * v[i+K-1] == 0){
            ans1 = max(abs(v[i]), v[i+K-1]);
        }else{
            ans1 = max(abs(v[i]), abs(v[i+K-1]));
        }
        ans = min(ans,ans1);
    }
    cout << ans;
}