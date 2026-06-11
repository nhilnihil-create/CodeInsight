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

    int n;cin>>n;
    if(n==3){
        cout<<"2 5 63"<<endl;return 0;
    }
    queue<int> q2,q3;vector<int> ans;
    for(int i=1;i<=30000;i++){
        if(i==2||i==3||i==9) continue;
        if(i%2==0){
            q2.push(i);
        }
        else if(i%3==0){
            q3.push(i);
        }
    }    
    //片方の条件を満たしに行く
    n-=3;
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(9);

    //もう片方の条件を満たしに行く
    if(n%2==0&&n>0){
        while(!q3.empty()&&n>2){
            ans.push_back(q3.front());q3.pop();
            n--;
        }
        int sum=2;
        while(n>1){
            sum+=q2.front();
            sum%=3;
            ans.push_back(q2.front());q2.pop();
            n--;
            if(n==1) break;
        }
        while(1){
            if((q2.front()+sum)%3==0){
                ans.push_back(q2.front());
                break;
            }
            q2.pop();
        }
    }
    else if(n>0){
        while(!q3.empty()&&n>1){
            ans.push_back(q3.front());q3.pop();
            n--;
        }
        int sum=2;
        while(n>1){
            sum+=q2.front();
            sum%=3;
            ans.push_back(q2.front());q2.pop();
            n--;
            if(n==1) break;
        }
        while(1){
            if((q2.front()+sum)%3==0){
                ans.push_back(q2.front());
                break;
            }
            q2.pop();
        }
    }
    rep(i,ans.size()){
        cout<<ans[i];
        cout<<(i==ans.size()-1?'\n':' ');
    }
    return 0;
}
