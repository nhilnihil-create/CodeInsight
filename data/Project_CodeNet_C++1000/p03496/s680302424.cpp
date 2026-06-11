#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n];
    set<ll> s;
    multiset<pair<ll,int> > ms;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ms.insert(make_pair(a[i],i));
        s.insert(a[i]);
    }
    auto itr1=ms.begin();
    auto itr2=ms.end();
    itr2--;
    vector<pair<int,int> > ans;
    if((*itr1).first<0&&(*itr2).first>0){
        s.clear();
        if(abs((*itr1).first)>abs((*itr2).first)){
            for(int i=0;i<n;i++){
                a[i]+=(*itr1).first;
                ans.pb(make_pair((*itr1).second+1,i+1));
                s.insert(a[i]);
            }
        }
        else{
            for(int i=0;i<n;i++){
                a[i]+=(*itr2).first;
                ans.pb(make_pair((*itr2).second+1,i+1));
                s.insert(a[i]);
            }
        }
    }
    if(*(s.begin())>=0){
        for(int i=1;i<n;i++){
            ans.pb(make_pair(i,i+1));
        }
    }else{
        for(int i=n;i>1;i--){
            ans.pb(make_pair(i,i-1));
        }
    }
    int maki=ans.size();
    cout << maki<<endl;
    for(int i=0;i<maki;i++){
        cout << ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
