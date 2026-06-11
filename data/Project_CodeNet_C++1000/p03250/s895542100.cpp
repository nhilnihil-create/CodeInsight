#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 2e5+6;

int main(){
	    ll A,B,C;
    cin>>A>>B>>C;
    ll maxn = 0;
    maxn = max(maxn,A*10 + B + C);
    maxn = max(maxn,A + B*10 + C);
    maxn = max(maxn,A + B + C*10);
 
    cout<<maxn;
    return 0;
	
}