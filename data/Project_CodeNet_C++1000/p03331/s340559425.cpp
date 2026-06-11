#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
typedef long long LL;
const LL mod = 1e9 + 7;
const int N = 3e5 + 5;

int n, sum, m;

int main() {
    cin>>n;
    m = n;
    while(m) {
    	sum += m%10;
    	m /= 10;
    }
    if(sum == 1) cout<<10<<endl;
    else cout<<sum<<endl;
}