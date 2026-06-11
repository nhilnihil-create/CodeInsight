#include <bits/stdc++.h>
#include <cstdio>
#include <chrono>
#include <random>
using namespace std;

#define DRACARYS ios_base::sync_with_stdio(false);cin.tie(NULL);cin.exceptions(cin.failbit);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define PI 3.14159265
const long long int MAXN = 2e5+10;
const long long int MINN = 1e5+10;
const long long int inf = 1e18+7;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi; 
typedef stack<int> st;

bool ch(int ind, int n, int q, string s, char qr[][2]){
    char curr=s[ind];
    for(int i=0;i<q;++i){
        if(qr[i][0]==curr){
            if(qr[i][1]=='L'){
                --ind;
                if(ind<0) return 1;
                else curr=s[ind];
            }
            else{
                ++ind;
                if(ind>=n) return 1;
                else curr=s[ind];
            }
        }
    }
    return 0;
} 
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    DRACARYS
    int n,q,a1=0,a2=0;
    string s;
    cin>>n>>q>>s;
    char qr[q][2];
    for(int i=0;i<q;++i) cin>>qr[i][0]>>qr[i][1];
    int l=0,h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(ch(mid,n,q,s,qr)) l=mid+1;
        else h=mid-1;
    }
    a1=l;
    l=0,h=n-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        //cout<<l<<" "<<h<<" "<<mid<<endl;
        if(ch(mid,n,q,s,qr)) h=mid-1;
        else l=mid+1;
    }
    a2=h;
    //cout<<a1<<" "<<a2<<endl;
    cout<<max(a2-a1+1,0)<<endl;
    return 0;
}