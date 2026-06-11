#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define MAX 100005
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;


int main(){
    int d,g;
    cin>>d>>g;
    vector<ll> p(d),c(d);
    rep(i,d){
        cin>>p[i]>>c[i];
    }
    ll score[1024]={};
    ll cnt[1024]={};
    ll min_cnt=LLONG_MAX;
    rep(i,pow(2,d)){
        int k=-1;
        rep(j,d){
            if(i>>j&1){
                score[i]+=(c[j]+p[j]*(j+1)*100);
                cnt[i]+=p[j];
            }else{
                k=j;
            }
        }
        rep(l,p[k]){
            if(score[i]>=g||k==-1){
                break;
            }
            score[i]+=((k+1)*100);
            cnt[i]++;
        }
        if(score[i]>=g){
            min_cnt=min(cnt[i],min_cnt);
        }
    }
    cout<<min_cnt<<endl;
    return 0;
}