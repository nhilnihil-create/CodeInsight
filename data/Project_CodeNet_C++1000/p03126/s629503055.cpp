#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<int,int>m;
    map<int,int>:: iterator itr;
    int n,p,k,a,sum=0;
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a;
            m[a]++;
        }
    }
    for(itr=m.begin();itr!=m.end();itr++){
        if(itr->second==n){
                sum++;
        }
    }
    cout<<sum;
    return 0;
}
