#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    vector<bool>a(n,false);
    for(int i=0;i<m;i++){
        int ind;
        cin>>ind;
        a[ind]=true;
    }
    int ans1=0,ans2=0;
    for(int i=x;i<n;i++){
        if(a[i])ans1++;
    }
    for(int i=x;i>=0;i--){
        if(a[i])ans2++;
    }
    cout<<min(ans1,ans2)<<endl;
    return 0;
}