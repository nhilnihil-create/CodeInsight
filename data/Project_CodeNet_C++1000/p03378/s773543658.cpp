#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;cin>>n>>m>>x;
    //5 - 0 1 2 3 4 5 -6 nos so n+2 is correct
    vector<int >a(n+1,0) ;
    for (int i=0,d;i<m;i++) {
        cin>>d;
        a[d]=1;
    }
    int min1=0,min2=0;
    for(int i=0;i<=x;i++)min1+=a[i];
    for(int i=x;i<=n;i++)min2+=a[i];
    cout<<min(min1,min2);
}