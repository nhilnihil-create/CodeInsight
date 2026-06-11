#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    vector<int>d(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[a[i]]++;
    }
    sort(d.begin(),d.end(),greater<int>());
    int tmp=0;
    for(int i=0;i<k;i++){
        tmp+=d[i];
    }
    cout<<n-tmp<<endl;
    
    return 0;
}