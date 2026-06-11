#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

ll N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> ans;
    int end = 0;
    if(N >= 0){
        for(int i = 0; i <= 50; ++i){
            if(N >> i & 1){
                ans.emplace_back(1);
                end = i;
                if(i & 1) N += 1LL << i;
            }else{
                ans.emplace_back(0);
            }
        }
    }else{
        N = abs(N);
        for(int i = 0; i <= 50; ++i){
            if(N >> i & 1){
                ans.emplace_back(1);
                end = i;
                if(!(i & 1)) N += 1LL << i;
            }else{
                ans.emplace_back(0);
            }
        }
    }
    for(int i = end; i >= 0; --i){
        cout << ans[i];
    }
    return 0;
}