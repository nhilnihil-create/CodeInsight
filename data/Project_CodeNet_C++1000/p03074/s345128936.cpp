#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi me;
    int sum =0;
    char now ='0';
    if(s[0]==now){
        me.push_back(0);
        me.push_back(0);
        }
    rep(i,n){
        if(now!=s[i]){
            me.push_back(sum);
            sum=1;
            now=s[i];
        }
        else sum++;
    }
    me.push_back(sum);
    vi ruiseki((int)me.size(),0);
    rep(i,me.size()){
        if(i==0)continue;
        ruiseki[i]=ruiseki[i-1]+me[i];
    }
    int ans =0;
    for(int  i = 0;i<ruiseki.size();i+=2){
        int right = i + k*2+1;
        if (right >= me.size()) right = (int)me.size() -1;
        ans = max(ans, ruiseki[right] - ruiseki[i]);
    }
    cout<<ans<<endl;
}
