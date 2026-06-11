#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	//
    //freopen("input.txt", "r", stdin);
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin>>n>>a>>b;
    cout<<(abs(a-b)&1 ? "Borys" : "Alice")<<endl;
}