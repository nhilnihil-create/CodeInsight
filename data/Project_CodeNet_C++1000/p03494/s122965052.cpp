#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> ans1(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(ans1[i]=0;a[i]%2==0;ans1[i]++){
            a[i]/=2;
        }
    }
    int ans=ans1[0];
    for(int i=1;i<n;i++){
        if(ans1[i]<ans)ans=ans1[i];
    }
    cout<<ans<<endl;
    return 0;
}