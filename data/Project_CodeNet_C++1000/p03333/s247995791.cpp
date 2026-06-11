#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int l[N], r[N];
multiset<pii> il,jl;
int n;

ll solve(int pr){
    for(int i = 0 ; i < n; i ++ ){
        il.insert(mp(l[i],r[i]));
        jl.insert(mp(r[i],l[i]));
    }
    ll answ = 0;
    int L, R;
    int pos=0;
    for(int i = 0 ; i < n; i ++ ){
        if(i % 2 == pr){
            auto it = il.end();
            -- it;
            L = it->fi;
            R = it->se;
            if(pos >= L && pos <= R){
                continue;
            }
            else{
                if(pos < L){
                    answ += L - pos;
                    pos = L;
                }
                else{
                    answ += pos - R;
                    pos = R;
                }
            }
            il.erase(il.find(mp(L,R)));
            jl.erase(jl.find(mp(R,L)));
        }
        else{
            auto it = jl.begin();
            L = it->se;
            R = it->fi;
            if(pos >= L && pos <= R){
                continue;
            }
            else{
                if(pos < L){
                    answ += L - pos;
                    pos = L;
                }
                else{
                    answ += pos - R;
                    pos = R;
                }
            }
            il.erase(il.find(mp(L,R)));
            jl.erase(jl.find(mp(R,L)));
        }
    }
    return answ+max(pos,-pos);
}

int main(){
    fastIO;
    cin >> n;
    for(int i = 0 ; i < n;  i ++ ){
        cin >> l[i] >> r[i]; 
    }
    cout << max(solve(0),solve(1));
    return 0;
}
