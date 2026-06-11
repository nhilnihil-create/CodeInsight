#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    int n,k; cin>>n>>k;
    string s; cin>>s;

    vector<int> num;
    int conti=1;
    if(s[0]=='0') num.push_back(0);
    rep(i,0,n-1){
        if(s[i]==s[i+1]){
            conti++;
        }else{
            num.push_back(conti);
            conti=1;
        }
    }
    num.push_back(conti);
    if(s[n-1]=='0') num.push_back(0);

    vector<int> cum(num.size());
    cum[0]=num[0];
    rep(i,0,num.size()-1){
        cum[i+1]=cum[i]+num[i+1];
    }

    if((cum.size()-1)/2<k){
        cout<<s.size()<<endl;
        return 0;
    }
    int ans=0;

    for(int i=0; i+2*k<cum.size(); i+=2){
        int temp;
        if(i==0){
            temp=cum[2*k];
        }else{
            temp=cum[i+2*k]-cum[i-1];
        }
        ans=max(ans,temp);
    }

    cout<<ans<<endl;
    
}