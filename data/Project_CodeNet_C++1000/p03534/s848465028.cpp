#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

int cnt[3];

signed main()
{
    string s; cin>>s;
    REP(i,s.size()) cnt[s[i]-'a']++;
    
    sort(cnt,cnt+3);
    if(cnt[2]-cnt[0]<=1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}
