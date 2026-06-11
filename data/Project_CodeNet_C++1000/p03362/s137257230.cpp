#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

// using namespace __gnu_pbds;
#define Init1 ios::sync_with_stdio(false)
#define Init2 cin.tie(0)
#define INF 0x3f3f3f3f
// #pragma GCC optimize(2)

const int N = 55555 + 105;

int prime[N], vis[N], tot = 0;
int c[6] = {0};
int main(){
    for(int i = 2; i < N; ++i){
        if(!vis[i]){
            prime[++tot] = i;
            for(int j = i + i; j < N; j += i)
                vis[j] = 1;
        }
    }
    vector<int>ans;
    for(int i = 1; i <= tot; ++i){
        if(prime[i] % 5 == 1) ans.push_back(prime[i]);
    }
    int n; cin>>n;
    for(int i = 1; i <= n; ++i) cout<<ans[i]<<" ";
    cout<<endl;
    // system("pause");
}