#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans;
    ans=n/111;
    ans=ans*111;
    if(n%111!=0&&n!=111){
        ans=ans+111;
    }
    cout<<ans<<endl;




    return 0;
}
