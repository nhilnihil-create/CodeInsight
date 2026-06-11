#include <bits/stdc++.h>

using namespace std;

const int INF=1e9+7;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ret=INF;
    for(int i=0;i<n;i++){
        int j=0;
        vector<int> temp,ans;
        while(j<n){
            if(a[j]<a[i]){
                if(temp.size()>=k){
                    sort(temp.begin(),temp.end());
                    for(int l=0;l<temp.size()-k+1;l++){
                        ans.push_back(temp[l]);
                    }
                }
                temp.resize(0);
                j++;
            }
            else{
                temp.push_back(a[j]);
                j++;
            }
        }
        if(temp.size()>=k){
            sort(temp.begin(),temp.end());
            for(int l=0;l<temp.size()-k+1;l++){
                ans.push_back(temp[l]);
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()>=q){
            ret=min(ret,ans[q-1]-ans[0]);
        }
    }
    cout<<ret<<endl;
    return 0;
}