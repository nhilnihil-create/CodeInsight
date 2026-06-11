#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(15)

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

bool cmp(int a,int b){
    return false;
}
int main(){
    int m,n,cnt=0;
    string s;

    cin >>n>>m;
    vi x(m);
    vi l(m-1);
    forN(i,m)cin>>x[i];
    sort(x.begin(),x.end());
    forN(i,m-1)l[i]=x[i+1]-x[i];
    sort(l.begin(),l.end());
    forN(i,m-n) cnt+=l[i];
    cout<<cnt<<endl;
}