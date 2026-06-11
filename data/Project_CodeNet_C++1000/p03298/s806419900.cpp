#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

int main(){
	int N;
    string S;
    cin>>N>>S;
    string mae=S.substr(0,N),ushi=S.substr(N,N);

    map<pair<string,string>,ll> ma;
    for(int bit=0;bit<(1<<N);bit++){
        string a="",b="";
        for(int i=0;i<N;i++){
            if(bit & (1<<i)) a+=ushi[i];
            else b+=ushi[i];
        }
        reverse(all(a));
        reverse(all(b));
        auto p=make_pair(a,b);
        ma[p]++;
    }

    ll res=0;
    for(int bit=0;bit<(1<<N);bit++){
        string a="",b="";
        for(int i=0;i<N;i++){
            if(bit & (1<<i)) a+=mae[i];
            else b+=mae[i];
        }
        auto p=make_pair(a,b);
        res+=ma[p];
    }
    cout<<res<<endl;
}