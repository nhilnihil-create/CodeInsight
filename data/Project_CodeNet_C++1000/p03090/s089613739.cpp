#include<bits/stdc++.h>
#define inf 2000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int,int> mii;
int main()
{
    int i,j,k;
    int n;
    cin>>n;
    vii edge;
    vector<vi> vec;
    for(i=1,j=n-(n&1);i<j;i++,j--){
        vi temp;
        temp.pb(i);
        temp.pb(j);
        vec.pb(temp);
    }
    if(n&1)
        vec.pb(vi(1,n));
    for(i=0;i<(int)vec.size()-1;i++){
        for(j=i+1;j<(int)vec.size();j++){
            for(auto vi: vec[i]){
                for(auto vj: vec[j])
                    edge.pb({vi,vj});

            }
        }
    }
    cout<<edge.size()<<endl;
    for(auto e: edge)
        cout<<e.fi<<" "<<e.se<<endl;
}
