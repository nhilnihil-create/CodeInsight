#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    string S; cin>>S;
    int cnt[3]={0};

    for (int i = 0; i < S.length(); ++i) {
        cnt[S[i]-'a']++;
    }

    sort(cnt,cnt+3);

    if(cnt[2]-cnt[0]<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
