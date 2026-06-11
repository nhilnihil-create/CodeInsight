#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int i;
    int N;
    int ans1=0,ans2=0;
    cin>>N;
    vector<int> v;
    rep(i,N){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    rep(i,N){
        if(i%2==0){
            ans1+=v[i];
        }else{
            ans2+=v[i];
        }
    }
    cout<<ans1-ans2<<endl;
}
