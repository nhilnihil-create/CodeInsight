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

int main(){
    int n,m,cnt=0;
    string s;

    int q;
    cin>>n>>q>>s;
    vi x(n+1,0);
    vpii lr(q);
    forN(i,q){
        pii tmp;
        cin >> tmp.first >> tmp.second;
        lr[i] = tmp;
    }
    int j=0;
    forS(i,1,n+1){
        if(s[i-1]=='A' && s[i]=='C') j++;
        x[i]=j;
    }
    forN(i,q){
        cout << x[lr[i].second-1] - x[lr[i].first-1] << endl;
    }
}
