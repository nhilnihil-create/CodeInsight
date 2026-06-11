#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int freq[MAX];
int cs[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=1; i<n; i++)
    {
        if(s[i]=='C' && s[i-1]=='A' )
            freq[i]=1;
        cs[i]=cs[i-1]+freq[i];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        int ans=cs[r]-cs[l-1];
        if(freq[l])
            ans--;
        cout<<ans<<endl;
    }

    return 0;
}
