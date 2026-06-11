#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;

    vector<int> sum(3);

    for(int i=0;i<s.size();i++){
        if(s[i]=='a')sum[0]++;
        else if(s[i]=='b')sum[1]++;
        else sum[2]++;
    }

    sort(sum.begin(),sum.end());

    bool ans=((sum[2]-sum[0])<2);

    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}