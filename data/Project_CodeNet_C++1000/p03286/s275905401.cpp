#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0)cout<<n;
    vector<long long>sei(1,1);
    vector<long long>hu(1,2);
    vector<long long>sei_sum(1,1);
    vector<long long>hu_sum(1,2);
    for(int i=0;sei_sum[i]<abs(n)*2;i++){
        sei.push_back(sei[i]*4);
        hu.push_back(hu[i]*4);
        sei_sum.push_back(sei_sum[i]+sei[i+1]);
        hu_sum.push_back(hu_sum[i]+hu[i+1]);
    }
    vector<int>ans(sei.size()*2,0);
    while(true){
        int x;
        if(n==0)break;
        if(n>0){
            int x=lower_bound(sei_sum.begin(),sei_sum.end(),n)-sei_sum.begin();
            ans[x*2]=1;
            n-=sei[x];
        }
        if(n<0){
            int x=lower_bound(hu_sum.begin(),hu_sum.end(),-1*n)-hu_sum.begin();
            ans[x*2+1]=1;
            n+=hu[x];
        }
    }
    while(ans.back()==0)ans.pop_back();
    for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
    cout<<endl;
    return 0;
}