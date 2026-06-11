#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define leading zero str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
string text="abcdefghijklmnopqrstuvwxyz";
const int maxn=1e6+7;
//        .--------------.
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'
bool cmp(const pair<ll,ll>& A,const pair<ll,ll>& B)
{
    return A.first < B.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector< pair<ll,ll> >v;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),cmp);
    ll sum=0;
    for(auto x: v){
        if(x.second>m){
            sum+=(x.first*m);
            break;
        }
        else{
            sum+=(x.first*x.second);
            m-=x.second;
        }
    }
    cout<<sum<<endl;
}
