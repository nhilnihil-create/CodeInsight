#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
typedef vector<int>         vi;
const int mod = 1000000007;






int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,change;
    cin>>n>>k;
    map<int,int>m;
    vi arr;
    for(int i =0;i<n;i++){
        int no;
        cin>>no;
        m[no]++;
    }
    if(k>=m.size()){
        cout<<0<<endl;
        return 0;
    }
    else{
        change  = m.size()-k;
        auto it = m.begin();
        for(int i =0;it!=m.end() && i <n;i++,it++){
                arr.pb(it->second);
        }
    }
    sort(all(arr));
    int ans=0;
    for(int i =0;i < change;i++){
        ans = ans + arr[i];
    }
    cout<<ans<<endl;








}




























































