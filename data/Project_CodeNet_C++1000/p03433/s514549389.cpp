#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,a;
    cin>>n>>a;
    int rem=n%500;
    cout<<(rem<=a?"Yes":"No")<<endl;
    return 0;
}