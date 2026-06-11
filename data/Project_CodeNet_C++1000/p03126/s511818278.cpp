#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(m+1);
    int ans=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            int b;
            cin>>b;
            a[b]++;
        }
    }
    for(int i=1;i<=m;i++){
        if(a[i]==n)ans++;
    }
    cout<<ans<<endl;
    return 0;
}