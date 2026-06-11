#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 1000000;

ll mod = INF;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    ll ans=0;
    map<ll,ll> m;
    for(int i=0;i<(int)s.size();i++){
        int num=(int)s[i]-(int)'a';
        m[num]++;
    }
    int single=0;
    vector<int> multi;
    for(int i=0;i<26;i++){
        if(m[i]>1){
            multi.push_back(m[i]);
        }else if(m[i]==1){
            single++;
        }
    }
    for(int i=0;i<single;i++){
        if(i==0)ans=1;
        ans=(ans*2)%mod;
    }
    if(ans==0)ans=1;
    for(int i=0;i<(int)multi.size();i++){
        ans=(ans*(multi[i]+1))%mod;
    }
    cout << ans-1<<endl;
    return 0;
}