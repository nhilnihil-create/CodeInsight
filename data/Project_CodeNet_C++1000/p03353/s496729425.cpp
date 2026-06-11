#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;

string deduplicate(string a) {
    sort(a.begin(),a.end());
    auto itr=unique(a.begin(),a.end());
    a.resize(itr-a.begin());
    return a;
}

vector<string> sdeduplicate(vector<string> a) {
    sort(a.begin(),a.end());
    auto itr=unique(a.begin(),a.end());
    a.resize(itr-a.begin());
    return a;
}

int main() {
    string s;
    int k;
    cin >> s;
    cin >> k;
    string t=s;
    int n=s.size();
    sort(t.begin(),t.end());
    string b=deduplicate(t);
    int cnt=k;
    rep(i,b.size()){
        vector<string> ans;
        rep(j,n) {
            if (s[j]==b[i]) {
                string tans;
                int u=min(n-j,k);
                rep(l,u) {
                    tans.push_back(s[j+l]);
                    ans.push_back(tans);
                }
            }
        }
        vector<string> aans=sdeduplicate(ans);
        if (aans.size()<cnt) cnt-=aans.size();
        else {
            cout << aans[cnt-1] << endl;
            return 0;
        }
    }
}