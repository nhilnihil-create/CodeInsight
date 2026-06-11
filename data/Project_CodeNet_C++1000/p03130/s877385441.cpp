#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long

const int N = 300030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    1e9+7;
int a[5];
int main()
{
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int mx=0;
for(int i=0;i<6;i++)
{
	int x;
	cin>>x;
	a[x]++;
	if(a[x]>mx)
	mx=a[x];
}
if(mx<=2)

cout<<"YES";
else
cout<<"NO";


}