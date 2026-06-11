#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define max 100005
using ll =long long;
using namespace std;

int num[3]={7,5,3};
ll n,ans=0;

int degit(ll num){
    int s=1;
    while((num/10)!=0){
        num/=10;
        s++;
    }
    return s;
}

void dfs(vector<int> &A ){
    if(A.size()==degit(n)+1)return;
    int flg1=0,flg2=0,flg3=0;
    ll m=0;
    rep(i,A.size()){
        m+=A[i]*pow(10,i);
        if(A[i]==3)flg1=1;
        if(A[i]==5)flg2=1;
        if(A[i]==7)flg3=1;
    }
    if(flg1==1&&flg2==1&&flg3==1&&m<=n)ans++;

    for(int i=0;i<3;i++){
        A.push_back(num[i]);
        dfs(A);
        A.pop_back();
    }
}
int main(){
    cin>>n;
    vector<int> A;
    dfs(A);
    cout<<ans<<endl;
    return 0;
}