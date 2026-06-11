#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n,b,c;
    cin>>n;
    vector<int>v(n);
    vector<int>v2(n);
    vector<int>v3(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    for(int i=0;i<n;i++){
        v3[i]=v[i]-v2[i];
    }
    int s=0;
    for(int i=0;i<n;i++){
        if(v3[i]>0)s+=v3[i];
    }
   cout<<s;
}
