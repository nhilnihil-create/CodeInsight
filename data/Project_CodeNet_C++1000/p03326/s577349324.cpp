#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> valppp(n);
    vector<int> valppm(n);
    vector<int> valpmp(n);
    vector<int> valpmm(n);
    vector<int> valmpp(n);
    vector<int> valmpm(n);
    vector<int> valmmp(n);
    vector<int> valmmm(n);
    for(int i = 0; i < n; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        valppp[i]=x+y+z;
        valppm[i]=x+y-z;
        valpmp[i]=x-y+z;
        valpmm[i]=x-y-z;
        valmpp[i]=-x+y+z;
        valmpm[i]=-x+y-z;
        valmmp[i]=-x-y+z;
        valmmm[i]=-x-y-z;
    }
    sort(valppp.rbegin(),valppp.rend());
    sort(valppm.rbegin(),valppm.rend());
    sort(valpmp.rbegin(),valpmp.rend());
    sort(valpmm.rbegin(),valpmm.rend());
    sort(valmpp.rbegin(),valmpp.rend());
    sort(valmpm.rbegin(),valmpm.rend());
    sort(valmmp.rbegin(),valmmp.rend());
    sort(valmmm.rbegin(),valmmm.rend());

    int sumppp=0;
    int sumppm=0;
    int sumpmp=0;
    int sumpmm=0;
    int summpp=0;
    int summpm=0;
    int summmp=0;
    int summmm=0;

    for(int i = 0; i < m; i++) {
        sumppp+=valppp[i];
        sumppm+=valppm[i];
        sumpmp+=valpmp[i];
        sumpmm+=valpmm[i];
        summpp+=valmpp[i];
        summpm+=valmpm[i];
        summmp+=valmmp[i];
        summmm+=valmmm[i];
    }
    int ans=max({sumppp,sumppm,sumpmp,sumpmm,summpp,summpm,summmp,summmm});
    cout << ans << "\n";
    return 0;
}