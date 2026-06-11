#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long a,b,n;
string ss;
int main(){
    cin>>n;
    vector<int>v(n+2,0);
    for (int i=1; i<=n; i++){
        cin>>v[i];
        b+=abs(v[i]-v[i-1]);
    }
    b+=abs(v[n]);
    for (int i=1; i<=n; i++){
        cout<<b-abs(v[i]-v[i-1])-abs(v[i]-v[i+1])+abs(v[i-1]-v[i+1])<<endl;
    }
}
