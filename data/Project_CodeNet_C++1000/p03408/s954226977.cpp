#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n;
    set<string>st;
    map<string,int>mp;
    int mx=0;
    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        st.insert(s);
        mp[s]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        mp[s]--;
    }
    for(auto i:st)
        mx=max(mx,mp[i]);
        cout<<mx<<endl;
    return 0;
}
