#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    cout<<(m > n ? 0 : n-m+1)<<"\n";
    return 0;
}