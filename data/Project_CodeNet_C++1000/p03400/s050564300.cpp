#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using vi = vector<int>;
using vl= vector<ll>;
using vs=vector<string>;

ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a);}
ll max(ll a, ll b) {if (a > b) return a; else return b;}
ll min(ll a, ll b) {if (a < b) return a; else return b;}
ll power(ll a,ll b) {ll i,p=1; for(i=0;i<b;i++){p*=a;} return p;}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
        ll n=0;
        cin>>n;
        ll d=0,x=0;
        cin>>d>>x;
        ll array[n]={0};
        ll sum=n;
        for(int i=0;i<n;i++){
            cin>>array[i];
            sum+=(d-1)/array[i];
        }
        sum+=x;
        cout<<sum;
        
        }

    return 0;
}
