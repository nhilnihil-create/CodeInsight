#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n,k;
    cin>>n>>k;
    char s[n];
    rep(i,n)cin>>s[i];
    vi d;
    int nowc=1;
    char now=s[0];
    for (int i=1;i<n;i++){
        if (now!=s[i]){
            d.push_back(nowc);
            nowc=1;
            now=s[i];
        }
        else nowc+=1;
    }
    d.push_back(nowc);
    int num=d.size();
    if (k>=num/2 && s[0]=='1'){
        cout<<n<<endl;
    }
    else if (s[0]=='0' && k>=double(num)/2.0){
        cout<<n<<endl;
    }
    else{
        if (s[0]=='1'){
            int ans=0;
            int ans1=0;
            rep(i,k){
                ans1+=d[2*i];
                ans1+=d[2*i+1];
            }
            ans1+=d[2*k];
            ans=ans1;
            for (int i=1;i+2*k+1<num;i+=2){
                ans1-=d[i-1];
                ans1-=d[i];
                ans1+=d[i+2*k];
                ans1+=d[i+2*k+1];
                ans=max(ans1,ans);
            }
            if (num%2==0){
                int ans2=0;
                rep(i,k){
                    ans2+=d[num-2*i-1];
                    ans2+=d[num-2*i-2];
                }
                ans=max(ans,ans2);
            }
            cout<<ans<<endl;
        }
        else{
            int ans=0;
            int ans1=0;
            rep(i,k){
                ans1+=d[2*i];
                ans1+=d[2*i+1];
            }
            //ans1+=d[2*k];
            ans=ans1;
            ans1-=d[0];
            ans1+=d[2*k];
            ans1+=d[2*k+1];
            ans=max(ans1,ans);
            for (int i=0;i+2*k+3<num;i+=2){
                //cout<<"!"<<endl;
                ans1-=d[i+1];
                ans1-=d[i+2];
                ans1+=d[i+2*k+2];
                ans1+=d[i+2*k+3];
                ans=max(ans1,ans);
            }
            int ans2=0;
            if(num%2==1){
            rep(i,k){
                ans2+=d[num-2*i-1];
                ans2+=d[num-2*i-2];
            }
            ans=max(ans,ans2);}
            
            cout<<ans<<endl;
        }
    }
    


    return 0;
}