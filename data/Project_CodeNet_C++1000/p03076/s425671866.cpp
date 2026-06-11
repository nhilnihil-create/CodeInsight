#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> n(5);
    for(int i=0;i<5;i++)
    cin>>n[i];
    vector<int> diff(5,0);
    for(int i=0;i<5;i++){
        while((n[i]+diff[i])%10!=0){
            diff[i]++;
        }
    }
    int max_diff=max(max(diff[0],diff[1]),max(diff[2],max(diff[3],diff[4])));
    int ans=0;
    for(int i=0;i<5;i++){
        ans+=n[i];
        ans+=diff[i];
    }
    cout<<ans-max_diff<<endl;
}