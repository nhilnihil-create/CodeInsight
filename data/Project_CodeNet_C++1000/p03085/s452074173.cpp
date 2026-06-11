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
#define FO ifstream fin("a.in");ofstream fout("a.out");
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

int main(){
    IO

    ll N,ans=0;
    char c;
    cin>>c;
    if(c=='A') cout<<'T';
    if(c=='T') cout<<'A';
    if(c=='C') cout<<'G';
    if(c=='G') cout<<'C';

    return(0);
}