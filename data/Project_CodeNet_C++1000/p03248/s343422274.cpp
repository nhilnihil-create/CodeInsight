#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;




int main(){
    string s;cin >> s;
    int n = s.length();
    if(s[n-1] == '1'||s[0] != '1'){
        puts("-1");
        return 0;
    }
    int sz = (n + 1) / 2;
    for (int i = 0; i < sz; i++) {
        if(s[i] != s[n-2-i]){
            puts("-1");
            return 0;
        }
    }
    vector<P> ans(n-1);
    int u=1,v=2;
    for (int i = 0; i < n-1; i++) {
        if(i > sz){
            ans[i] = make_pair(u,v);
            v++;
        }
        else{
            if(s[i] == '1'){
                ans[i] = make_pair(u,v);
                u = v;
                v++;
            }
            else{
                ans[i] = make_pair(u,v);
                v++;
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << ans[i].fs << " " << ans[i].sc << endl;
    }
    return 0;
}
