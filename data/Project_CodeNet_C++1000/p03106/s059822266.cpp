#include <bits/stdc++.h>

using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;



int main() {
const ll INF = 1001001001;
const ld PI = 3.14159265358979323846;
int A,B,K,count=0,ans;
cin>>A>>B>>K;
repr3(i,min(A,B)){
    if((A%i==0)&&(B%i==0)){
        count++;
        if(count==K){
            ans=i;
            break;
        }
    }
}
cout<<ans<<endl;
return 0;
}

