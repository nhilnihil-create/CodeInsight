#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll=long long;
const int MAXN=100010;

bool check(int m,int k){
    if((1<<m)-1>=k)return true;
    return false;
}
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    int res=0;

    int m,k;
    cin>>m>>k;
    if(m==1){
        if(k==0){
            for(int i=0;i<(1<<m);i++){
                ans.push_back(i);
                ans.push_back(i);
            }
        }else{
            ans.push_back(-1);
        }
    }
    else if(check(m,k)){
        ans.push_back(k);
        for(int i=0;i<(1<<m);i++){
            if(i==k)continue;
            ans.push_back(i);
        }
        ans.push_back(k);
        for(int i=(1<<m)-1;i>=0;i--){
            if(i==k)continue;
            ans.push_back(i);
        }
    }else{//
        ans.push_back(-1);
    }

    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans.back()<<endl;



    return 0;
}