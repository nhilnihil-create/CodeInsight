#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(12) <<x<<endl;

bool cmp(pair<int,pair<string,int>> &a,pair<int,pair<string,int>> &b){
    if(a.sd.ft!=b.sd.ft) return a.sd.ft<b.sd.ft;
    return a.sd.sd>b.sd.sd;
}
int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif

int n;
vector<pair<int,pair<string,int>>> v;
cin>>n;
//cout<<n<<endl;
forn(i,1,n+1){
    string nom;
    cin>>nom;
    int p;
    cin>>p;
    v.pb({i,{nom,p}});
}
sort(v.begin(),v.end(),cmp);
for(auto &x:v){
    cout<<x.ft<<endl;
}
}
