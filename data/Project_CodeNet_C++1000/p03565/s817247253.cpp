#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; 
using namespace std;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
typedef long long  ll;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
#define pb push_back

#define F first
#define S second
#define SZ(a) int((a).size())
#define ALL(a) a.begin(),a.end()
#define fr(i,x,y) for(int i=x;i<y;i++)
#define frr(i,x,y) for(int i=x-1;i>=y;i--)
#define inf 1e18+1
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll power(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;}a=a*a;b>>=1;}return ans;}
ll powerm(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;ans%=mod;}a=a*a;a%=mod;b>>=1;}return ans%mod;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

void solve()
{
    string s,t;
    cin>>s>>t;
    ll fg=0;
    VL visit(SZ(s),0);
    stack<string> st;
    //ll bad=false;
    ll idx=-1;
    fr(i,0,SZ(s))
    {
        bool fg=true;

        if(i+SZ(t)>SZ(s))
            continue;
        //cout<<i<<endl;
        fr(j,0,SZ(t))
        {
            if(s[i+j]!='?'&&s[i+j]!=t[j])
                fg=false;
        }
        if(fg)
            idx=i;
    }
    // fr(i,0,SZ(s))
    // {
    //     if(s[i]==t[0]&&(i+SZ(t))<=SZ(s))
    //     {
    //         fg=1;
    //         fr(j,0,SZ(t))
    //         {
    //             if(s[i+j]=='?'||s[i+j]==t[j])
    //             {
    //                 if(s[i+j]=='?')
    //                     visit[i+j]=1;
    //                 s[i+j]=t[j];
                    
    //             }
    //             else
    //             {
    //                 fg=0;
    //                 break;
    //             }
    //         }
    //         //cout<<s<<fg<<endl;
    //         if(fg==0)
    //         {
    //             fr(i,0,SZ(s))
    //             {
    //                 if(visit[i]==1)
    //                 {
    //                     visit[i]=0;
    //                     s[i]='?';
    //                 }
    //             }
    //         }
    //         else
    //         {
    //             st.push(s);
    //             fr(i,0,SZ(s))
    //             {
    //                 if(visit[i]==1)
    //                 {
    //                     visit[i]=0;
    //                     s[i]='?';
    //                 }
    //             }
    //         }
    //         fg=0;
    //     }
    // }
    //cout<<idx<<endl;
    if(idx<0)
    {
        cout<<"UNRESTORABLE\n";
        return;
    }
    fr(i,0,SZ(t))
    {
        s[i+idx]=t[i];
    }
    fr(i,0,SZ(s))
    {
        if(s[i]=='?')
            s[i]='a';
    }
    // if(SZ(st)==0)
    // {
    //     ll last=-1;
    //     fr(i,0,SZ(s))
    //     {
    //         ll ct=0;
    //         fr(j,0,SZ(t))
    //         {
    //             if((i+j)>=SZ(s))
    //                 continue;
    //             if(s[i+j]=='?'&&(i+j)<SZ(s))
    //                 ct++;
    //         }
    //         if(ct==SZ(t))
    //             last=i;
    //     }
    //     if(last==-1)
    //         cout<<"UNRESTORABLE\n";
    //     else
    //     {
    //         fr(i,0,SZ(t))
    //         {
    //             s[last+i]=t[i];
    //         }
    //         fr(i,0,SZ(s))
    //         {
    //             if(s[i]=='?')
    //                 s[i]='a';
    //         }
    //         cout<<s<<endl;
    //     }
    // }
    // else
    // {
    //     ll last=-1;
    //     //cout<<s<<endl;
    //     fr(i,0,SZ(s))
    //     {
    //         ll ct=0;
    //         fr(j,0,SZ(t))
    //         {
    //             if((i+j)>=SZ(s))
    //                 continue;
    //             if(s[i+j]=='?'&&(i+j)<SZ(s))
    //                 ct++;
    //         }
    //         if(ct==SZ(t))
    //             last=i;
    //     }
    //     if(last!=-1)
    //     {
    //         fr(i,0,SZ(t))
    //         {
    //             s[last+i]=t[i];
    //         }
    //         fr(i,0,SZ(s))
    //         {
    //             if(s[i]=='?')
    //                 s[i]='a';
    //         }
    //         //cout<<s<<endl;
    //     }
    //     else
    //     {
    //         s=string(SZ(s),'{');
    //     }
    //     string str=st.top();
    //     fr(i,0,SZ(str))
    //     {
    //         if(str[i]=='?')
    //         {
    //             str[i]='a';
    //         }
    //     }
    //     if(s<str)
    //         cout<<"yo"<<s<<endl;
    //     else
    //         cout<<str<<endl;
    // }
    cout<<s<<endl;
    return;
}
int main()
{
    IOS;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
*/
// BITMASK:
// 1)When some constrall is of the order of 15-20, think of bitmask DP.
// 2)When some constrall is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algorithm