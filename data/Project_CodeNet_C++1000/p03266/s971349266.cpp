#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
//#define int long long
typedef long long ll;
typedef pair<int,int> P;

ll combi(ll a, ll b){
    ll rep=1;
    for(int i=a;i>a-b;i--) rep*=i;
    for(int i=b;i>0;i--) rep/=i;
    return rep;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> mod[k];
    for(int i=1;i<=n;i++){
        mod[i%k].push_back(i);
    }
    ll ans=0;
    if(k%2==0){
        ans=combi(mod[0].size(),1)+combi(mod[0].size(),2)*6+combi(mod[0].size(),3)*6;
        ans+=combi(mod[k/2].size(),1)+combi(mod[k/2].size(),2)*6+combi(mod[k/2].size(),3)*6;
    }
    else{
        ans=combi(mod[0].size(),1)+combi(mod[0].size(),2)*6+combi(mod[0].size(),3)*6;
    }
    cout << ans << endl;

}