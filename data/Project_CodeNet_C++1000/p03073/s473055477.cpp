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
    string s;
    cin>>s;
    int n=s.size();
    string t="";
    for(int i=0;i<n;i++){
        if(i%2==0)t+="0";
        else t+="1";
    }
    int cnt=0,cnt1=0;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])cnt++;
    }
    t="";
    for(int i=0;i<n;i++){
        if(i%2==0)t+="1";
        else t+="0";
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])cnt1++;
    }
    cout<<min(cnt1,cnt)<<endl;
}
