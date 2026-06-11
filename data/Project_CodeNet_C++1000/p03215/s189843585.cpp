#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 

int  A(int x){
    if(x>=0)return x;
    else return -x;
}

int ans[1010][1010];

int main(void){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n),seq;
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        ll sum = 0;
        for(ll j=i;j<n;j++){
            sum+=a[j];
            seq.push_back(sum);
        }
    }
    for(ll i=40;i>=0;i--){
        vector<ll>seq1,seq2;
        for(ll j=0;j<seq.size();j++){
            if(seq[j]&(1LL<<i))seq1.push_back(seq[j]);
            else seq2.push_back(seq[j]);
        }
        if(seq1.size()<k)continue;
        else{
            if(seq1.size()==k){
                seq = seq1;
                break;
            }
            else seq = seq1;
        }
    }
    ll ans = (1LL<<40)-1LL;
    for(ll i=0;i<seq.size();i++)ans&=seq[i];
    cout<<ans<<endl;
    return 0;
}