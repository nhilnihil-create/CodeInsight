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
    string s; cin >> s;
    if(s == "zyxwvutsrqponmlkjihgfedcba"){
        cout << -1 << endl;
        return 0;
    }
    int n = s.size();
    if(n < 26){
        vector<bool> used(26,false);
        rep(i,n){
            used[s[i]-'a'] = true;
        }
        rep(i,26){
            if(!used[i]){
                s += i+'a';
                break;
            }
        }
        cout << s << endl;
        return 0;
    }
    for(int i = n-1; i >= 1; i--){
        if(s[i] > s[i-1]){
            vector<bool> used(26,false);
            rep(j,i){
                used[s[j]-'a'] = true;
            }
            repr(j,s[i-1]-'a',26){
                if(!used[j]){
                    s[i-1] = j+'a';
                    break;
                }
            }
            rep(j,i) cout << s[j];
            cout << endl;
            return 0;
        }
    }
}

