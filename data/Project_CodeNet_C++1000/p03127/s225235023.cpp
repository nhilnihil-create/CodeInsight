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

int gcd(int,int);
int main(){
    int n,m,cnt=0;
    string s;

    cin >> n;
    vi a(n);
    forN(i,n){
        cin >> a[i];
    }
    int p=0;
    forN(i,n){
        p=gcd(p,a[i]);
    }
    cout << p<<endl;
}
int gcd(int x, int y){
    int a=x,b=y;
    if(a==0||b==0) return max(a,b);
    if(a<b) swap(int,a,b);
    int tmp;
    while((tmp=a%b)!=0){
        a=b;b=tmp;
    }
    return b;
}