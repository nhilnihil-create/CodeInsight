#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> st;
    int cnt=0;
    char ref=s[0];
    for(int i = 0; i < n; i++) {
        if(s[i]==ref) cnt++;
        else{
            st.emplace_back(cnt);
            ref=s[i];
            cnt=1;
        }
    }
    if(cnt!=0) st.emplace_back(cnt);
    if(s[0]=='0') st.insert(st.begin(),0);
    if(s[n-1]=='0') st.emplace_back(0);

    vector<int> b(st.size()+1);
    b[0]=0;
    for(int i = 0; i < st.size(); i++) {
        b[i+1]=b[i]+st[i];
    }

    int ans=0;
    for(int i = 0; i < st.size(); i+=2) {
        int tans;
        tans=b[min((int)st.size(),i+2*k+1)]-b[i];
        ans=max(tans,ans);
    }
    cout << ans << "\n";
    return 0;
}