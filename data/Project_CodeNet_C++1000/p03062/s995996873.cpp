#include<bits/stdc++.h>
#define INF 1e9+5
#define INT long long
using namespace std;
int main(){
    int n;
    int a[100005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int cnt=0,mn=INF;
    INT sum=0;
    for(int i=0;i<n;i++){
        if(a[i]<0) cnt++;
        mn = min(mn,abs(a[i]));
        sum+=abs(a[i]);
    }
    if(cnt%2==1) sum-=mn*2;
    cout<<sum<<endl;
    return 0;
}

