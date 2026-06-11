#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<int,int> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
/*
..#..
.#.#. 
#.#.#
 */
int a,b;
//白がa,黒がb
cin>>a>>b;
a--;b--;
vector<vector<char>> s(100,vector<char>(100,'#'));
for(int i=50;i<100;i++)for(int j=0;j<100;j++)s[i][j]='.';
for(int i=0;i<49;i+=2){
    if(a==0)break;
    for(int j=0;j<100;j++){
        if(j%2==0){
            s[i][j]='.';
            a--;
        }
        if(a==0)break;
    }
}
for(int i=51;i<100;i+=2){
    if(b==0)break;
    for(int j=0;j<100;j++){
        if(j%2==0){
            s[i][j]='#';
            b--;
        }
        if(b==0)break;
    }
}
cout<<100<<" "<<100<<endl;
 for(int i=0;i<100;i++){
  for(int j=0;j<100;j++)cout<<s[i][j];
  cout<<endl;
 }
}
