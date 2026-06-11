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
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

int gcd(int,int);
int main(){
    int n,m,cnt=0;

    cin >> n;
    vi a(n),l(n+1), r(n+1);
    forN(i,n){
        cin >> a[i];
    }
    l[0] = 0;
    r[n] = 0;
    m=0;
    forS(i,1,n+1){
        l[i]=gcd(l[i-1],a[i-1]);
        r[n-i]=gcd(a[n-i],r[n-i+1]);
    }
    forN(i,n){
        int tmp = gcd(l[i],r[i+1]);
        m=max(m,tmp);
    }
    cout << m << endl;
}
int gcd(int x,int y){
    int a=x,b=y;
    if(a<b){
        swap(int,a,b);
    }
    int tmp;
    if(b==0) return a;
    while((tmp=a%b)!=0){
        a=b;b=tmp;
    }
    return b;
}
