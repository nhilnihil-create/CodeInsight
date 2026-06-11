# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
int cnt1,cnt2;
vector<int>letak;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        char isi=s[i];
        if(isi=='B')letak.pb(i);
    }
    ll byk=letak.size();
    int idx=s.size()-1-byk+1;
    ll ans=0;
    for(auto isi:letak){
        ans+=(idx-isi);
        idx++;
    }
    cout<<ans<<endl;
}