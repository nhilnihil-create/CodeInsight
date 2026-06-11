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

bool cmp(vi,vi);
int main(){
    int n,m,cnt=0;
    string s;

    int c;
    cin >>n>>m>>c;
    vi b(m);
    vector<vi> a(n,vi(m));
    forN(i,m) cin >> b[i] ;
    forN(i,n){
        forN(j,m) cin>>a[i][j];
    }
    forN(i,n){
        int tmp=0;
        forN(j,m) tmp+=a[i][j]*b[j];
        tmp += c;
        if(tmp > 0){
            cnt++;
        }
    }
    cout << cnt << endl;
}