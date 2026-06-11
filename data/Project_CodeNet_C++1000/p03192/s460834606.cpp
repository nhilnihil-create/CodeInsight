    #include <bits/stdc++.h>
    using namespace std;
    signed main(){
    int x,ans=0;
    cin>>x;
    while(x != 0){
    if(x%10 == 2){
    ans++;
    }
    x/=10;
    }
    cout<<ans<<endl;
    return(0);
    }