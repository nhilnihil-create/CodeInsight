#include<bits/stdc++.h>
using namespace std;
main(){
    int n;
    cin>>n;
    vector<vector<int>> acts;
    for(int i=0;i<n;i++){
        vector<int> dayActs;
        for(int j=0;j<3;j++){
            int temp;
            cin>>temp;
            dayActs.push_back(temp);
        }
        acts.push_back(dayActs);
    }
    vector<vector<int>> happiness(n,vector<int>(3,0));
    happiness[0][0]=acts[0][0];
    happiness[0][1]=acts[0][1];
    happiness[0][2]=acts[0][2];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k) continue;
                happiness[i][j]=max(happiness[i][j],happiness[i-1][k]+acts[i][j]);
            }
        }
    }
    cout<<max({happiness[n-1][0],happiness[n-1][1],happiness[n-1][2]});

}