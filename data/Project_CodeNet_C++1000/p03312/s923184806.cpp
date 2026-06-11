#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    //真ん中の仕切りを動かして全探索する
    //真ん中の仕切りを動かした後に最適に左右の仕切りを動かす．
    //この時，左右の仕切りは当然右にしか動かないので結局O(n)でこの問題は解けます．（きっと）

    int n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll A=a[0],B=a[1],C,D;
    int left=0;
    int right;{
        //2<=i<nとこでに分割して差を小さく
        ll p=0,q=0;int l=2,r=n-1;
        while(l<=r){
            if(p>q){
                // 右を進める
                q+=a[r];
                r--;
            }
            else{
                p+=a[l];
                l++;
            }
        }
        right=l;C=p;D=q;
    }
    right--;
    ll ans=max({A,B,C,D})-min({A,B,C,D});

    for(int center=2;center<n-2;center++){
        B+=a[center];C-=a[center];
        //貪欲に移動させる
        //left
        while(true){
            if(left<center&&abs(A-B)>abs(A+a[left+1]-B+a[left+1])){
                A+=a[left+1];B-=a[left+1];
                left++;
            }
            else break;
        }
        //right
        while(true){
            if(right<n&&abs(C-D)>abs(C+a[right+1]-D+a[right+1])){
                C+=a[right+1];D-=a[right+1];
                right++;
            }
            else break;
        }
        chmin(ans,max({A,B,C,D})-min({A,B,C,D}));
        // cout<<endl;
        // cout<<ans<<endl;
        // cout<<left<<' '<<center<<' '<<right<<endl;
        // cout<<A<<' '<<B<<' '<<C<<' '<<D<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
