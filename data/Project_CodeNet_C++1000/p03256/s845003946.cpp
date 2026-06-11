/// Kazuki Hoshino


#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pi> vpi;
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for(int i =a; i >=b; i--)
#define f first
#define ss second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
//#define endl '\n'
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ll n, m , x, y, adeg[202020], bdeg[202020] ;
vi adj[202020];
bool deleted[202020];
string s;
queue<int> q;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


cin >> n >> m;
cin >> s;



rep(i, 1, m){
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
}

rep(i, 1, n){
    for(auto t : adj[i]){
        if(s[t-1]=='A')adeg[i]++;
        if(s[t-1]=='B')bdeg[i]++;
    }
    if(adeg[i]<1 || bdeg[i]<1)  {q.push(i);deleted[i]=true;}
}

while(!q.empty()){

    x = q.front();q.pop();

    for(auto t: adj[x]){

        if(s[x-1]=='A')adeg[t]--;
        if(s[x-1]=='B')bdeg[t]--;

        if((adeg[t]<1 || bdeg[t]<1) && !deleted[t] ){
            q.push(t);deleted[t]=true;
        }

    }

}

rep(i, 1, n){
    if(!deleted[i]){
        cout << "Yes" << endl;
        return 0;
    }
}

cout <<"No"<< endl;


return 0;}
///....
