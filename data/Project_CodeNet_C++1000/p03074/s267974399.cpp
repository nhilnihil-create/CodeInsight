#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main(){
    int n,k;cin>>n>>k;
    int num[n][2];
    string s;cin>>s;
    int mx = 0;
    int ch=1;
    int cnt = 0;
    rep(i,n){
        if(s[i]=='0'){
           if(ch)num[cnt][0]=i;
           ch = 0;
           if(s[i+1]=='1'||i==n-1){
               num[cnt][1]=i;
               cnt++;
           }
        }
        if(s[i]=='1'){
            ch = 1;
        }
    }
   // rep(i,cnt)cout<<"n"<<num[i][0]<<num[i][1]<<endl;
    if(cnt<k){
        cout<<n<<endl;
        return 0;
    }
    mx =max(num[k][0]-1,mx);
    for (int i = 0; i < cnt; i++)
    {
       int r,l;
       if(i>0)l = num[i-1][1]+1;
       else l = 0;
       if(k+i<cnt){
           r = num[i+k][0]-1;
       }else{
           r = n-1;
       }
       //cout<<l<<r<<endl;
       mx = max(mx,r-l+1);
    }
    
    cout<<mx<<endl;
    return 0;
}