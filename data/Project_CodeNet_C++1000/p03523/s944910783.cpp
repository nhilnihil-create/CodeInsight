#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF 1e9+7
#define LLINF 1e18
// #define int ll
using namespace std;
const int MOD = 1e9 +7;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    bool can=0;
    cin>>s;
    if(s=="AKIHABARA" ||s=="AKIHABAR" ||s=="AKIHABRA" ||s=="AKIHBARA"||s=="KIHABARA"||s=="AKIHABR"||s=="AKIHBAR"||s=="AKIHBRA"||s=="KIHABAR"||s=="KIHABRA"||s=="KIHBARA"||s=="KIHBRA"||s=="KIHBAR"||s=="KIHABR"||s=="AKIHBR"||s=="KIHBR") can=1;
    if(can) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}