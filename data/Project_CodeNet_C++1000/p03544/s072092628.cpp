#include<bits/stdc++.h>
using namespace std;
#define int long long

/*int findlucas(int n){
    if(n==0)
    return 2;
    else if(n==1)
    return 1;
    else
    return (findlucas(n-1)+findlucas(n-2));
}*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int lucas[n];
    lucas[0]=2;
    lucas[1]=1;
    for(int i=2;i<=n;i++)
    lucas[i]=lucas[i-1]+lucas[i-2];
    cout<<lucas[n];
}