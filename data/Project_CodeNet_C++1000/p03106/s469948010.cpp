#include <bits/stdc++.h>
#define pb push_back
#define p push
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define plli pair<ll,int>
#define pill pair<ill>
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, k; cin >> a >> b >> k;
    set<int> st, st2;
    vector<int> vec, vec2;
    for(int i = 1; i*i <= a; i++){
        if(a%i != 0)continue;
        st.insert(i); st.insert(a/i);
    }
    for(int i = 1; i*i <= b; i++){
        if(b%i != 0)continue;
        st2.insert(i);
        st2.insert(b/i);
    }
    for(auto i : st)vec.pb(i); for(auto i : st2)vec2.pb(i);
    vector<int> ans;
    for(auto i : vec){
        for(auto j : vec2){
            if(i == j)ans.pb(i);
        }
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans[k-1] << endl;
    return 0;
}

