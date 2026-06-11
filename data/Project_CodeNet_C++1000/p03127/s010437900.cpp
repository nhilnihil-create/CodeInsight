#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin>>n;
    ll ele;
    cin>>ele;
    ll gcd = ele;
    n--;
    while(n--)
    {
        cin>>ele;
        gcd = __gcd(gcd,ele);
    }
    cout<<gcd<<endl;
	return 0;
}