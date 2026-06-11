/// Kazuki Hoshino


#include<bits/stdc++.h>
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

ll k,l,p,mni;
ld mn = inf;
set<ll> s;
vector<pair<ld, ld>> v;

ld sum(ll x){
ld res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
return res;
}

void add(ll x){
ll d[202];
ll p = 1, i = 1;
ll c=0, temp = x;
while(temp>0){
    d[i]=temp%10;
    temp/=10;
    c+=9*p;
    p*=10;
    v.pb({((ld)(temp*p + c) / sum(temp*p +c)), temp*p +c } );
    i++;
}

}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

cin >> k;

ll cur = 1;
s.insert(cur);
while(s.size()<k){

v.pb({cur/sum(cur+1) , cur+1 });
add(cur+1);
sort(all(v));
s.insert(v[0].ss);
cur = v[0].ss;
v.clear();
}




for(auto t: s){
    cout << t << endl;
}


return 0;}
