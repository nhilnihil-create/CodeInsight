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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    string s;
    cin>>n>>k>>s;
    string t="AC";
    int cnt[n+2]={0};
    int b[n+2]={0};
    for(int i=0;i+1<n;i++){
        if(s.substr(i,2)==t){
            cnt[i+1]=1;
        }
    }
    b[0]=cnt[0];
    for(int i=1;i<n;i++)b[i]=b[i-1]+cnt[i];
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        r--;
        if(l!=0)cout<<b[r]-b[l-1]<<endl;
        else cout<<b[r]<<endl;
    }
}
