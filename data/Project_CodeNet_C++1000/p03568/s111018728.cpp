#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,a=1,b=1;
    cin>>n;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        a *= 3;
        if(x%2==0) b *= 2;
    }
    cout<<a-b;
}