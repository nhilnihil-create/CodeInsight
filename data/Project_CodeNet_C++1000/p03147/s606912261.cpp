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

    cin>>n;
    vi h(n);
    forN(i,n)cin>>h[i];
    int tmp=h[0];
    forN(i,n-1){
        int x;
        if((x=h[i+1]-h[i])<0){
            cnt-=x;
        }
        tmp=min(tmp,h[i+1]);
    }
    cnt+=(h[n-1]>0?h[n-1]:0);
    cout << cnt << endl;
}
