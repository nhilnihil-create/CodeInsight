#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e3+5;
int arr[MAXN];
vector<int> res;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    while(n){
        int mx = 0;
        for(int i=1;i<=n;i++){
            if(arr[i] == i){
                mx = i;
            }
        }
        if(mx == 0){
            cout<<-1<<endl;
            return 0;
        }
        res.push_back(mx);
        for(int i=mx;i<n;i++){
            arr[i] = arr[i+1];
        }
        n--;
    }
    reverse(res.begin(),res.end());
    for(int x:res){
        cout<<x<<endl;
    }
    
}