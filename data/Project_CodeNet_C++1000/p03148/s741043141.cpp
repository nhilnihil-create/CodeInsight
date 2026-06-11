#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vii vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>
#define ff first
#define ss second
#define pb push_back
#define read freopen("alu.txt","r",stdin);
#define write freopen("vorta.txt","w",stdout);
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define PI 2*acos(0.0)
#define DEBUG(x) cerr << #x << " = " << x << endl

const int MAX = 3e5 + 5, MOD = 1e9 + 7, MAXLG = log2(MAX)+1;
const ll inf = 1e18 + 5;

pii arr[MAX];
multiset<pii>st;
map<int,int>mp;
int main(){

    fastio;
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i].ss>>arr[i].ff;
    }
    sort(arr, arr+n, greater<pii>());

    ll val = 0;
    for(int i=0; i<k; i++){
        val += arr[i].ff;
        mp[arr[i].ss]++;
        st.insert(arr[i]);
    }

    ll var = mp.size();
    ll ans = val + var * var;

    for(int i=k; i<n; i++){
        if(!mp[arr[i].ss]){
            while(!st.empty()){
                if(mp[(*st.begin()).ss] > 1){
                    mp[(*st.begin()).ss]--;
                    mp[arr[i].ss]++;
                    val -= (*st.begin()).ff;
                    val += arr[i].ff;
                    var++;
                    st.erase(st.begin());
                    st.insert(arr[i]);
                    break;
                }
                else st.erase(st.begin());
            }
            if(st.empty()) break;

            ll temp = val + var * var;
            ans = max(ans, temp);
        }
    }

    cout<<ans<<"\n";

}


