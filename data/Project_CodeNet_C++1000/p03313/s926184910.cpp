#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fill(x,v) memset(x,v,sizeof(x))
#define all(x) (x).begin(), (x).end()
#define trace(x) cout << #x <<": " << x << endl
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define pi acos(-1)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int MAX = 1<<19;

vi arr;

bool vis[MAX];
set<pair<int, int> > lista[MAX];

void merge(int a, int b){
    lista[a].insert(*(lista[b].begin()));
    lista[a].insert(*(lista[b].rbegin()));
    while(lista[a].size() > 2){
        lista[a].erase(*(lista[a].rbegin()));
    }
}

void solve(){
    ll n;
    cin >> n;
    arr.resize(1<<n);
    for(int i = 0; i < (1<<n); i++){
        cin >> arr[i];
    }
    for(int i = 1; i < (1<<n); i++){
        lista[i].insert(mp(-arr[0],0));
        lista[i].insert(mp(-arr[i],i));
    }

    fill(vis, 0);
    queue<int> cola;
    cola.push(0);
    vis[0] = true;
    int curr, aux,aux2;
    while(!cola.empty()){
        curr = cola.front();
        cola.pop();
        aux = curr;
        for(int i = 0; i < n; i++){
            if((aux&1) == 0){
                aux2 = curr | (1<<i);
                if(curr){
                    merge(aux2, curr);
                }
                if(!vis[aux2]){
                    vis[aux2] = true;
                    cola.push(aux2);
                }
            }
            aux >>= 1;
        }
    }
    ll curr2 = -1;
    ll suma;
    int a, b;
    for(int i = 1; i < (1<<n); i++){
        a = (*(lista[i].begin())).ff;
        b = (*(lista[i].rbegin())).ff;
        suma = -a - b;
        if(suma > curr2) curr2 = suma;
        cout << curr2 << endl;
    }
    
    return ;
}

int main(){
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}