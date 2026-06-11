#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>

using ll = long long;
const ll inf = 1001001001;

int countac(string a, int b, int c){
    int count = 0;
    b--;
    c--;
    rep(j, b, c){
        if(a[j] == 'A'&& a[j+1] == 'C')count++;
    }
    return count;
}

int main(){
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int>l(q);
    vector<int>r(q);
    vector<int>aclength(n,0);
    rep(i, 0, q){
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    int cntac = 0;
    string temps;
    temps += s[0];
    rep(i, 1, n){
        temps += s[i];
        if(temps[i-1] == 'A' && temps[i] == 'C')cntac++;
        aclength[i] = cntac;
    }
    rep(i, 0, q){
        cout << aclength[r[i]] - aclength[l[i]] << endl;
    }
}