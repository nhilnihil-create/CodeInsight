#include<bits/stdc++.h>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
#define ull unsigned long long int
#define ll long long int
#define MAX 1000000007
//1e9+7
#define pll pair<ll,ll>
#define pii pair<int,int>
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TEST ll t;cin>>t;while(t--)
ll sizes[100001];
ll arr[100001];

bool ok=true;
ll A[100001];
pll B[100001];

ll root(ll i){
    while(i!=arr[i]) i=arr[i];
    return(i);
}
void Union(ll i,ll j){
    ll root_i=root(i),root_j=root(j);
    if(root_i==root_j) return;
    if(sizes[root_i]>sizes[root_j]) swap(root_i,root_j);
    sizes[root_j]+=sizes[root_i];
    arr[root_i]=arr[root_j];
    return;
}
bool prime[10000];
vector<ll> v;
void era(){
    memset(prime,true,sizeof prime);
    for(ll p=2;p*p<=10000;p++){
        if(prime[p]){

            for(ll q=p*p;q<=10000;q+=p){
                prime[q]=false;
            }
        }
    }

    return;
}
/*

ll dif(string s,string p){
    ll a=(s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
    ll b=(p[0]-'0')*100+(p[1]-'0')*10+(p[2]-'0');
    return(abs(a-b));
}
bool is357(ll i){
    bool a=false,b=false,c=false;
    while(i){
        if(i%10==3) a=true;
        else if(i%10==5) b=true;
        else if(i%10==7) c=true;
        else return(false);
        i/=10;
    }
    return(a&b&c);
}

void dfs(ll i,bool a,bool b,bool c){
    if(i>N) return;
    if(a&& b&&c) ans++;
    dfs(i*10+3,true,b,c);
    dfs(i*10+5,a,true,c);
    dfs(i*10+7,a,b,true);
    return;
}
*/
ll count_div[101];
void cnt(ll N){

    for(ll i=0;i<v.size();i++){
        if(v[i]>N) break;
        while(N%v[i]==0){
            N/=v[i];
            count_div[v[i]]++;
        }
    }
    return;
}
int main(){
    IO
    ofstream fout("a.out");
    ll N,ans=0;
    cin>>N;
    memset(count_div,0,sizeof count_div);

    era();

    for(ll i=2;i<=100;i++) if(prime[i]) v.push_back(i);

    for(ll i=2;i<=N;i++) cnt(i);
    //for(ll i=0;i<=100;i++) fout<<i<<" "<<count_div[i]<<endl;
    ll M=v.size();
    for(ll i=0;i<M;i++) if(count_div[v[i]]+1>=75) ans++;
    for(ll i=0;i<M;i++){
        for(ll j=0;j<M;j++){
            if(i==j) continue;

            if(count_div[v[i]]+1>=3 && count_div[v[j]]+1>=25) {
                    ans++;
                    //cout<<v[i]<<" "<<v[j]<<endl;
            }
            if(count_div[v[i]]+1>=5 && count_div[v[j]]+1>=15) {
                    ans++;
                    //cout<<v[i]<<" "<<v[j]<<endl;
                }

        }
    }
    for(ll i=0;i<M;i++)
        for(ll j=i+1;j<M;j++)
    for(ll k=0;k<M;k++){
        if(i==j || j==k || i==k) continue;

        if(count_div[v[i]]+1>=5 && count_div[v[j]]+1>=5 && count_div[v[k]]+1>=3) {
                ans++;
        //cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
        }
    }

    cout<<ans;
    return(0);
}
