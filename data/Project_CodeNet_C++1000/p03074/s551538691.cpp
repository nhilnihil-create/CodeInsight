#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
    int n,k,count = 0,sum = 0, ans = -1; cin >> n >> k;
    string s; cin >> s;
    vector<int> l,r;
    s += 'a';

    rep(i,n){
        if(s[i] == '1') count ++;
        else{
            if(l.size() != 0)r.push_back(l[l.size()-1]+count);
            while(s[i+1] == '0'){
                count ++;
                i ++;
            }
            l.push_back(count+1);
            count = 0;
        }
    }
    if(count == n){
        cout << n;
        return 0;
    }
    r.push_back(l[l.size()-1]+count);

    /*
    rep(i,l.size()) cout << l[i] << " " ;
    cout << endl;
    rep(i,r.size()) cout << r[i] << " ";
    cout << endl;
    */
    if(r.size() == 0 || r.size() <= k) {
        cout << n;
        return 0;
    }

    for(int i = r.size()-1; i >= k-1; i --){
        sum = 0;
        rep(j,k) {
            if(j == 0) sum += r[i];
            else sum += l[i-j];
        }
        ans = max(ans,sum);
    }
    cout << ans;

}
