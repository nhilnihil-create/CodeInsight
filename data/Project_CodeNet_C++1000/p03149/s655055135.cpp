#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int cnt[10]={};
    for(int i=0;i<4;i++){
        int n;
        cin>>n;
        cnt[n]++;
    }
    if(cnt[1]&&cnt[9]&&cnt[7]&&cnt[4]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
