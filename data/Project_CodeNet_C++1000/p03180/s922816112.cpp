#include<bits/stdc++.h>
using namespace std; 
//Important observation about this question is, it's enough
//to know whether given subset of rabits either belong
//to any group or doesn't belong to any group, in that way
//you will have 2^n subsets (where 0 represents they donot
//belong to any group and 1 represents they belong to some
//group, keep in mind we don't care which group, because
//in the process of transition we would have considered
//the best way to group all those already grouped rabbits)
//going from 0 to 2^n-1, first we will have none of them
//belonging to any group, i.e 0 and we find all the subsets
//of rabbits not belonging to any group and update the 
//max of the current mask, which also contains all the already
//available rabbits. This works because if the current group
//of rabbits which were formed from non-grouped rabbits 
//is better than including both these and already grouped rabbits
//then we can just put those already grouped rabbits
//in different groups and their max score of the group
//they belong will be 0
//Time complexity : O(2^(2n)+2^(n)n^2)
//Source : Errichto's youtube stream
vector<long long> dp;
vector<long long> pre;
long long score_so_far;
void group(int i,const vector<int>& not_grouped,int mask,int cur_group){
    if(i==not_grouped.size()){
        dp[mask] = max(dp[mask],score_so_far+pre[cur_group]);
        return;
    }
    group(i+1,not_grouped,mask,cur_group);
    group(i+1,not_grouped,mask^(1<<not_grouped[i]),cur_group^(1<<not_grouped[i]));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dp.resize(1<<n,LONG_LONG_MIN);
    pre.resize(1<<n,0);
    for(int mask=0;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                for(int j=i+1;j<n;j++){
                    if(mask&(1<<j)){
                        pre[mask]+=a[i][j];
                    }
                }
            }
        }
    }
    dp[0] = 0;
    for(int mask=0;mask<(1<<n);mask++){
        vector<int> not_grouped;
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))){
                not_grouped.push_back(i);
            }
        }
        score_so_far = dp[mask];
        group(0,not_grouped,mask,0);
    }
    cout<<dp[(1<<n)-1]<<"\n";
    return 0;
}