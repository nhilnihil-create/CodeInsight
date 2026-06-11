#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a,b;
    cin>>a>>b;
    cout<<((a*b)%2==0?"Even":"Odd");
    
    return 0;
}
