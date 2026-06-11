#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int m=1e9+7;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    fastio
    int n;
    cin>>n;
    int fp=n/100;
    int sp=n%100;
    if(fp>=1 && fp<=12){
        if(sp>=1 && sp<=12) cout<<"AMBIGUOUS";
        else cout<<"MMYY";
    }
    else{
        if(sp>=1 && sp<=12) cout<<"YYMM";
        else cout<<"NA";
    }
    return 0;
}