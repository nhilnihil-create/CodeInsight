#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;


int main() {

int N;
cin>>N;
ll A[N];
rep(i,N){
    cin>>A[i];
}
ll sum=0;
ll count=0;
int right=0;
rep(left,N){
    while((right<N)&&(sum+A[right])==(sum^A[right])){
        sum+=A[right];
        
        right++;
    }
    count+=right-left;
    if(right==left)right++;
    else{
        sum-=A[left];
   
    }
}
cout<<count<<endl;
return 0;
}