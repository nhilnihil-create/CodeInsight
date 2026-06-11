#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
bool dpx[8000][17001],dpy[8000][17001];
int main(){
string s;
int x,y;
cin>>s>>x>>y;
int mid=16001/2;
int t=0;
int j=0;
for(int i=0;i<s.size();i++){
    if(t%2==0){
        int cnt=0;
        while(i+cnt<s.size()&&s[i+cnt]!='T'){cnt++;}
        //cout<<cnt<<endl;
        if(j==0){
            dpx[0][mid+cnt]=true;
        }
        else{
            for(int d=0;d<16050;d++){
                if(cnt+d<16050&&dpx[j-1][cnt+d])dpx[j][d]=true;
                else if(d-cnt>=0&&dpx[j-1][d-cnt])dpx[j][d]=true;
            }
        }
        i+=cnt;
        j++;
    }
    if(i<s.size()&&s[i]=='T')t++;
}

int k=0;
dpy[0][mid]=true;
t=0;
for(int i=0;i<s.size();i++){
    if(t%2==1){
        int cnt=0;
        while(i+cnt<s.size()&&s[i+cnt]!='T'){cnt++;}
            for(int d=0;d<16050;d++){
                if(cnt+d<16050&&dpy[k][cnt+d])dpy[k+1][d]=true;
                else if(d-cnt>=0&&dpy[k][d-cnt])dpy[k+1][d]=true;
            }
        i+=cnt;
        k++;
    }
    if(i<s.size()&&s[i]=='T')t++;
}
if(dpx[j-1][mid+x]&&dpy[k][mid+y])cout<<"Yes"<<endl;
else cout<<"No"<<endl;
}
