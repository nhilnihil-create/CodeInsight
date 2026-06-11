#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int z=0;
    if(s[0]!='1'||s[n-1]!='0') z=1;
    rep(i,n-1) if(s[i]!=s[n-i-2]) z=1;
    if(z){
        cout<<-1;
        return 0;
    }
    int a=1;
    rep(i,n-1){
        cout<<a<<" "<<i+2<<"\n";
        if(s[i]=='1') a=i+2;
    }
}