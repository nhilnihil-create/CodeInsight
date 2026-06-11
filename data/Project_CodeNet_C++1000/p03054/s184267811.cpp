#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repA(a,i,n) for(int i=a;i<n;i++)
#define trav(a,x)for(auto &a: x)
#define fll(a) memset(a,-1,sizeof(a));
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define fst first
#define sec second
#define itr(it,x) for(auto it=x.begin();it!=x.end();it++)
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
typedef vector<int>vi;
typedef map<int,int>ma;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
void fopen()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
}
int main()
{
    fastio;
    //fopen();
    int h,w,n,x,y;
    cin>>h>>w>>n>>x>>y;
    string s,t;
    cin>>s>>t;
    int  tl=0,tr=0,tu=0,td=0;
    int sr=0,sl=0,su=0,sd=0;
    rep(i,n)
    {
        if(s[i]=='L')tl+=1;
        else if(s[i]=='R')tr+=1;
        else if(s[i]=='U')tu+=1;
        else td+=1;
        if(y-tl+sr<1 || y+tr-sl>w || x-tu+sd<1 || x+td-su>h)cout<<"NO",exit(0);
        if(t[i]=='R' && y-tl+sr<w)sr++;
        else if(t[i]=='L' && y+tr-sl>1)sl++;
        else if(t[i]=='D' && x-tu+sd<h)sd++;
        else if(t[i]=='U' && x+td-su>1)su++;
    }
    cout<<"YES";
}
