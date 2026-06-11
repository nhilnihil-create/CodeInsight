#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define nl cout<<"\n"
#define dbg(x) cout<<x<<" ";
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define UM unordered_map<int,int>
#define ULL unordered_map<ll,int>
void fun(){
    ll a,b,k;   cin>>a>>b>>k;
    fi(a,b+1){
        if(i<a+k||i>b-k)
            cout<<i<<"\n";
        else
            i=b-k;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fun();
}