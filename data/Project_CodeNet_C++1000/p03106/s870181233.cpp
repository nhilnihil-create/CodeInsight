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

    int a,b,k;
    cin>>a>>b>>k;
    int i;
    for(i=100;cnt<k&&i>0;i--){
        if(a%i ==0 && b%i==0){
            cnt++;
        }
    }
    cout << i+1 << endl;
}