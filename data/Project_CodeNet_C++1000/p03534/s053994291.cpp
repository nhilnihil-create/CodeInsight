#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
map<char,ll> mp;
string mae,usiro;
pair<ll,int> p[ohara];
map<char,int> che;

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>s;
    rep(i,Size(s)){
        mp[s[i]]++;
    }
    if(Size(s)==1){
        Cout("YES");
        return 0;
    }
    if(mp['a']==0&&mp['b']==0)Cout("NO");
    else if(mp['a']==0&&mp['c']==0)Cout("NO");
    else if(mp['b']==0&&mp['c']==0)Cout("NO");
    else if(mp['a']==0){
        if(mp['b']==1&&mp['c']==1)Cout("YES");
        else Cout("NO");
    }
    else if(mp['b']==0){
        if(mp['a']==1&&mp['c']==1)Cout("YES");
        else Cout("NO");
    }
    else if(mp['c']==0){
        if(mp['a']==1&&mp['b']==1)Cout("YES");
        else Cout("NO");
    }
    else{
        ans=0;
        int ok=0;
        //abc
        rep(i,Size(s)){
            if(i%3==0){
                if(mp['a']==0)ok=1;
                mp['a']--;
            }
            else if(i%3==1){
                if(mp['b']==0)ok=1;
                mp['b']--;
            }
            else{
                if(mp['c']==0)ok=1;
                mp['c']--;
            }
        }
        if(!ok)ans=1;

        ///////////

        ok=0;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        rep(i,Size(s)){
            mp[s[i]]++;
        }
        //abc
        rep(i,Size(s)){
            if(i%3==0){
                if(mp['a']==0)ok=1;
                mp['a']--;
            }
            else if(i%3==1){
                if(mp['c']==0)ok=1;
                mp['c']--;
            }
            else{
                if(mp['b']==0)ok=1;
                mp['b']--;
            }
        }
        if(!ok)ans=1;

        ok=0;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        rep(i,Size(s)){
            mp[s[i]]++;
        }
        //abc
        rep(i,Size(s)){
            if(i%3==0){
                if(mp['b']==0)ok=1;
                mp['b']--;
            }
            else if(i%3==1){
                if(mp['a']==0)ok=1;
                mp['a']--;
            }
            else{
                if(mp['c']==0)ok=1;
                mp['c']--;
            }
        }
        if(!ok)ans=1;

        ok=0;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        rep(i,Size(s)){
            mp[s[i]]++;
        }
        //abc
        rep(i,Size(s)){
            if(i%3==0){
                if(mp['b']==0)ok=1;
                mp['b']--;
            }
            else if(i%3==1){
                if(mp['c']==0)ok=1;
                mp['c']--;
            }
            else{
                if(mp['a']==0)ok=1;
                mp['a']--;
            }
        }
        if(!ok)ans=1;

        ok=0;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        rep(i,Size(s)){
            mp[s[i]]++;
        }
        //abc
        rep(i,Size(s)){
            if(i%3==0){
                if(mp['c']==0)ok=1;
                mp['c']--;
            }
            else if(i%3==1){
                if(mp['a']==0)ok=1;
                mp['a']--;
            }
            else{
                if(mp['b']==0)ok=1;
                mp['b']--;
            }
        }
        if(!ok)ans=1;

        ok=0;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        rep(i,Size(s)){
            mp[s[i]]++;
        }
        //abc
        rep(i,Size(s)){
            if(i%3==0){
                if(mp['c']==0)ok=1;
                mp['c']--;
            }
            else if(i%3==1){
                if(mp['b']==0)ok=1;
                mp['b']--;
            }
            else{
                if(mp['a']==0)ok=1;
                mp['a']--;
            }
        }
        if(!ok)ans=1;

        if(ans)Cout("YES");
        else Cout("NO");
    }
    return 0;
}
