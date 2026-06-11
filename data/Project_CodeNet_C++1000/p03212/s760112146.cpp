#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

ll N;

void judge(ll n, ll use, ll &counter){

    if(use==0b111) counter++;
    if(n*10+3<=N) judge(n*10+3,use|0b001,counter);
    if(n*10+5<=N) judge(n*10+5,use|0b010,counter);
    if(n*10+7<=N) judge(n*10+7,use|0b100,counter);

    else
    {
        return;
    }
    



}

int main(){
    cin>>N;
    ll res=0;
    judge(0,0,res);
    cout<<res<<endl;

}