#include <bits/stdc++.h>

using namespace std;

int main() {
int a,n,ans=0;
cin>>n>>a;

n%=500;
if(n>a) cout<<"No";
else cout<<"Yes";
cout<<endl;
}