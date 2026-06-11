/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
#define IOS  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const double pi=2*acos(0.0);
const double esp=1e-9;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int len[3005][3005];
int main() {

    //IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;
    for(int cs=1; cs<=test; ++cs) {
        string s,t,ts,ans;
        s+='#',t+='#';
        cin>>ts;
        s+=ts;
        cin>>ts;
        t+=ts;
        for(int i=1; i<sz(s); ++i) {
            for(int j=1; j<sz(t); ++j) {
                if(s[i]==t[j]) {
                    len[i][j]=len[i-1][j-1]+1;
                } else {
                    len[i][j]=max(len[i][j-1],len[i-1][j]);
                }
            }
        }
        int i=sz(s)-1,j=sz(t)-1;
        while(i>0&&j>0) {
            if(s[i]==t[j]) {
                ans+=s[i];
                --i,--j;

            } else if(len[i][j]==len[i][j-1]) {
                --j;
            } else {
                --i;
            }
        }
        reverse(ans.begin(),ans.end());
        if(sz(ans))
            cout<<ans<<endl;
        else cout<<' ';
    }
    return 0;
}

