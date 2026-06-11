#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<ll> H={INF,2,5,5,4,5,6,3,7,6};
ll M;
vector<string> A(10);
vector<ll> a(10);

//ans[i]: the maximum number that can be shaped by i matches
vector<string> ans(10001,"");


string F(ll x){
    if(x==0)return "";
    if(ans[x]!="")return ans[x];
    string rec="NG";
    for(ll i=0;i<M;i++){
        if(x-H[a[i]]<0||F(x-H[a[i]])=="NG")continue;
        if(rec=="NG"||F(x-H[a[i]]).size()+1>rec.size()){
            rec=F(x-H[a[i]])+A[i];
        }
        if(F(x-H[a[i]]).size()+1==rec.size()){
            chmax(rec,F(x-H[a[i]])+A[i]);
        }
    ;}
    return ans[x]=rec;
}




int main(){
    ll N;
    cin >> N;
    cin >> M;

    for(ll i=0;i<M;i++){
        cin>>A[i];
        a[i]=stoi(A[i]);
    ;}
    A[M]="0";
    a[M]=0;

    for(ll i=1;i<8;i++){
        ans[i]=="NG";
    ;}
    for(ll i=0;i<8;i++){
        for(ll j=0;j<M;j++){
            if(i-a[j]>=0&&ans[i-a[j]]==""){
                ans[i]="";
            }
        ;}
    ;}
    

    print(F(N));
    
    

    
    return 0;
}
