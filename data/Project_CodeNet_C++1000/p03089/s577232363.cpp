#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<int> nums(101,0);
    for (int i=1; i<=n; i++){
        cin >> nums[i];
    }
    int del = 0;
    stack<int> process;
    for(int i=0; i<n; i++){
        int idx = -1;
        for(int j=1; j<=n-i; j++){
            if(nums[j]==j) idx=j;
        }
        if(idx==-1){
            cout << -1 << endl;
            return 0;
        }
        process.push(idx);
        for(int j=idx; j<=n-i; j++) nums[j]=nums[j+1];
    }
    for (int i=0; i<n; i++){
        cout << process.top() << endl;
        process.pop();
    }
}