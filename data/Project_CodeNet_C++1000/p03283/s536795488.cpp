#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array)
#define inin freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
const int N=2000005;
vector<int> adj[505];


int main(){
    //inin
    IOS
    int n,m,q;
    cin>>n>>m>>q;
    int aa,bb,cc,dd;
    fo(i,m){
        cin>>aa>>bb;
        cc=min(aa,bb);
        dd=max(aa,bb);
        adj[cc].pb(dd);

    }
    //dbg(sz(adj[1]));
    FOR(i,1,n){
        if(sz(adj[i])) sort(all(adj[i]));
    }
    while(q--){
        cin>>aa>>bb;
        int count=0;
        cc=min(aa,bb);
        dd=max(aa,bb);
        FOR(i,cc,dd){
        int tmp=upper_bound(all(adj[i]),dd)-adj[i].begin();
        // dbg2(i,tmp);
        count+=tmp;
        }
        cout<<count<<endl;

    }

    
}