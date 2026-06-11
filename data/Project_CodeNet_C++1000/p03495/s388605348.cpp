#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
#define f first
#define s second
#define ll long long
#define ld long double
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int M=2e5+5;

int main() {
    IO
    int k,n,x,freq[M]={},ans=0;
    set<int>s;
    set<int>::iterator it;
    vector<int>v;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        freq[x]++;
        s.insert(x);
    }
    if(s.size()<=k){
        return cout<<0,0;
    }
    for(it=s.begin();it!=s.end();it++){
        v.push_back(freq[*it]);
    }
    sort(v.rbegin(),v.rend());
    for(int i=k;i<v.size();i++)
        ans+=v[i];
    cout<<ans;

    return 0;
}
