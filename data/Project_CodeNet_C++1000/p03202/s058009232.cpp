/// Kazuki Hoshino


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define dmp(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
//#define endl '\n'
typedef tree<
int,
null_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
int n,a[202020];
map<int,int> mp;

bool chk(int x){
       mp.clear();
       int cur = 0;
       bool ans = true;
       for(int i=1;i<=n;i++){
              if(a[i]>cur){
                     cur = a[i];
                     continue;
              }
              else {
                     while(!mp.empty() && mp.rbegin()->fs>=a[i]){
                            mp.erase(mp.rbegin()->fs);
                     }
                     mp[a[i]-1]++;
                     cur = a[i]-1;
                     while(mp[cur]>=x){
                            mp.erase(cur);
                            cur--;
                            mp[cur]++;
                            if(cur<0){
                                   ans = false;
                            }
                     }
              }
              if(!ans)break;
              cur = a[i];
       }
       return ans;
}

signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

cin >> n ;
for(int i=1;i<=n;i++){
       cin >> a[i];
}
bool flag = true;
for(int i=1;i<=n;i++){
       if(a[i]>a[i-1])continue;
       else flag = false;
}
if(flag){
       cout << 1 << endl;
       return 0;
}

int l = 1, r = n+1;
while(r-l>1){

       int mid = (l+r)/2;
       if(chk(mid)){
              r = mid;
       }
       else l = mid;
}

cout << r << endl;

return 0;}
///....
