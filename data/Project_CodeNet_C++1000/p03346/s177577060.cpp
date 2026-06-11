#include<bits/stdc++.h>
#define inf 2000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
#define rng_23 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int,int> mii;
int ara[200001],pos[200001];
int main()
{
    int i,j,k;
    int n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>ara[i];
        pos[ara[i]]=i;
    }
    int mx=0;
    i=1,j=2;
    while(i<=n){
        while(pos[j]>pos[j-1] && j<=n)
            j++;
        mx=max(mx,j-i);
        i=j;
        j++;
        //cout<<i<<endl;
    }
    cout<<n-mx;
}
