#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, m, i, ans=0, money=0;
    map<string, long long> mpr, mpb;
    cin >> n;
    for(i=0;i<n;i++){
        string s;
        cin >> s;
        mpb[s]++;
    }
    cin >> m;
    for(i=0;i<m;i++){
        string s;
        cin >> s;
        mpr[s]++;
    }
    for(auto x : mpb){
        if(x.second>mpr[x.first]) money=x.second-mpr[x.first];
        ans=max(ans, money);
    }
    cout << ans <<endl;
    return 0;
}
