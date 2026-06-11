#include <bits/stdc++.h>
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    int n;
    cin>>n;
    vector<int> vec1(n),vec2(n);
    for(i=0;i<n;i++){
        cin>>vec1[i];
    }
    for(i=0;i<n;i++){
        cin>>vec2[i];
    }
    long long int ans=0,maxv=0;
    for(i=0;i<n;i++){
        ans=0;
        for(j=0;j<n;j++){
            if(j<=i)ans+=vec1[j];
            if(j>=i)ans+=vec2[j];
        }
        maxv=max(maxv,ans);
    }
    cout<<maxv<<endl;
}