#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;


typedef pair<int,int> pa;

stack<int>s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,f;cin>>n;
    if(n==0) {
        cout<<0;return 0;
    }
    if(n>=0) f=1;
    else f=-1;
    n=abs(n);
   while(n){
       int k=n/2;
       if(n%2){
        s.push(1);
        if(f==-1) k++;
       }
       else  s.push(0);
       f=-f;
       n=k;
   }

    while(s.size()) {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
