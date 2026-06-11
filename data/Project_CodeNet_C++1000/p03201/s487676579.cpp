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
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    multiset<int> st;
    rep(i,N) st.insert(A[i]);
    int ans = 0;
    while(!st.empty()){
        auto p = st.end();
        p--;
        int x = *p;
        int k = x;
        int cnt = 0;
        while(k > 0){
            k /= 2;
            cnt++;
        }
        int d = (1<<cnt)-x;
        st.erase(p);
        auto p2 = st.find(d);
        if(p2 != st.end()){
            st.erase(p2);
            ans++;
        }
    }
    cout << ans << endl;
}