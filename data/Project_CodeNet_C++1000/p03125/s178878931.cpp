#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (long long i = 0; i < (long long) (n); i++)
using ll=long long;
using vi = vector<int>;
using vll = vector<ll>;

const int mod = 1000000007;
// const int mod = 998244353;

int main(){
    int a,b;
    cin >> a >> b;
    if(b%a==0)
        cout<<a+b<<endl;
    else
    	cout<<b-a<<endl;
 
}