#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> o(5),v(5);
    for(int i=0;i<5;i++){
        cin>>o[i];
        v[i]=i;
    }

    int ans=1e9;
    do{
        int cnt=0;
        for(int i=0;i<5;i++){
            if(i==4) cnt+=o[v[i]];
            else{
                cnt+=(o[v[i]]+10-1)/10*10;
            }
        }
        ans=min(cnt,ans);
    }while(prev_permutation(v.rbegin(),v.rend()));
    cout<<ans<<endl;
}