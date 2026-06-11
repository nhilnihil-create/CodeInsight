#include <bits/stdc++.h>
#define ll long long
#define ld long double

#define sonic ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

ll a[100010];



int main () {
sonic

int n1,n2,n3,n4;
cin>>n1>>n2>>n3>>n4;

int q = 0;

if(n1 == n2 || n1 == n3 || n1 == n4 || n2 == n3 || n2 == n4 || n3 == n4) {cout<<"NO";return 0;}


if(n1 == 1 || n2 == 1 || n3 == 1 || n4 == 1) { q++;}
if(n1 == 9 || n2 == 9 || n3 == 9 || n4 == 9) {q++;}
if(n1 == 7 || n2 == 7 || n3 == 7 || n4 == 7) {q++;}
if(n1 == 4 || n2 == 4 || n3 == 4 || n4 == 4) {q++;}

if(q == 4) {cout<<"YES";}
else cout<<"NO";

return 0;
}