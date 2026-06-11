#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,l[11],sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    for(int i=0;i<n-1;i++){
        sum+=l[i];
    }
    if(sum>l[n-1]){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
