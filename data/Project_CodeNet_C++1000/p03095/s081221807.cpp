# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
const int mod=1e9+7;
unordered_map<char,int>byk;
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;

    cin>>n;
    cin>>s;
    for(auto isi:s){
        byk[isi]++;
    }   
    ll ans=1;
    for(int i='a';i<='z';i++){
        ans=mul(ans,byk[i]+1);
    }
    cout<<(ans-1 +mod)%mod<<endl;
}