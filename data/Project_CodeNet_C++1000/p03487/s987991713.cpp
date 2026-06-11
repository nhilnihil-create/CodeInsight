#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
using namespace std;
using ll=long long;
using ld=long double;
#define ssort(n) sort((n).begin(),(n).end())
typedef pair<int,int> P;

int main()
{
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N)cin >> a[i];
    map<ll,ll> b;
    stack<ll> stack_b;
    rep(i,N){
        if(!b.count(a[i])){
            b[a[i]]=1;
            stack_b.push(a[i]);
        }else{
            b[a[i]]++;
        }
    }
    ll val;
    ll count=0;
    while(!stack_b.empty()){
        val=stack_b.top();
        stack_b.pop();
        
        if(b[val]>=val){
            count+=b[val]-val;
        }

        else{
            count+=b[val];
        }
    }
    cout << count << endl;
}