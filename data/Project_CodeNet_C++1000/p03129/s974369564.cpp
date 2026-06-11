#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a%2==0){
        if(a/2>=b) cout<<"YES\n";
        else cout<<"NO\n";
    }
    else{
        if(a/2+1>=b) cout<<"YES";
        else cout<<"NO\n";
    }
}
