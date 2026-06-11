#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int keta_sum(long long n){
    int res=0;
    while(n>0){
        res+=(n%10);
        n/=10;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin>>k;
    vector<long long> v;
    set<long long> st;
    for(int j=0;j<=12;j++){
        for(int i=1;i<=999;i++){
            long long tmp=i;
            for(int k=0;k<j;k++)tmp=tmp*10+9;
            if(st.count(tmp))continue;
            v.push_back(tmp);
            st.insert(tmp);
        }
    }
    for(int i=0;i<v.size();i++){
        bool f=true;
        for(int j=i+1;j<v.size();j++){
            if(v[i]*keta_sum(v[j])>v[j]*keta_sum(v[i])){
                f=false;
                break;
            }
        }
        if(f){
            cout<<v[i]<<endl;
            k--;
            if(k==0)break;
        }
    }

}