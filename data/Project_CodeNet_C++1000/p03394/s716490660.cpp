#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N; cin >> N;
    if(N == 3){
        cout << 2 << " " << 5 << " " << 63 << endl;
        return 0;
    }
    if(N == 4){
        cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
        return 0;
    }
    if(N == 5){
        cout << 2 << " " << 3 << " " << 4 << " " << 6 << " " << 9 << endl;
        return 0;
    }
    vector<int> ans;
    repr(i,1,30001){
        if(i % 2 == 0 || i % 3 == 0){
            ans.push_back(i);
            if(ans.size() == N) break;
        }
    }
    ll sum = 0;
    rep(i,N){
        sum += ans[i];
    }
    if(sum % 6 == 2){
        repr(i,ans[N-1]+1,30001){
            if(i % 6 == 0){
                ans[4] = i;
                break;
            }
        }
    }
    if(sum % 6 == 3){
        repr(i,ans[N-1]+1,30001){
            if(i % 6 == 0){
                ans[5] = i;
                break;
            }
        }
    }
    if(sum % 6 == 5){
        repr(i,ans[N-1]+1,30001){
            if(i % 6 == 4){
                ans[5] = i;
                break;
            }
        }
    }
    rep(i,N) cout << ans[i] << " ";
    cout << endl;

}

