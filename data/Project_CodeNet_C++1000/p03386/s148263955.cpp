#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,k;
    cin>>a>>b>>k;
    int i = a;
    for(;i<a+k && i<=b;i++){
        cout<<i<<"\n";
    }
    i = max(i,b-k+1);
    for(;i<=b;i++){
        cout<<i<<"\n";
    }
    return 0;
}
