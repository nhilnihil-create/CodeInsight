#include <algorithm>
#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for (int i = 0; i <(int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
//mapの使い方　カウントするとき便利
int main() {
int n,m;cin>>n>>m;
int a[n];
map<int,int> count;
vector<int> num;
rep(i,n){
 cin>>a[i];
 count[a[i]]++;
}
for(auto p:count){
 num.push_back(p.second);
}
sort(all(num));
int ans=0;
if(num.size()>m){
    for(int i=0;i<num.size()-m;i++){
        ans+=num[i];
    }
}
else ans=0;
cout<<ans<<endl;
}