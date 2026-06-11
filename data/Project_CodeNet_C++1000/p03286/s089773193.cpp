#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int64_t N; cin>>N;


    if(!N){
        cout<<0<<endl;
        return 0;
    } 

    vector<int64_t> pV{1},mV{0},sum_pV{1},sum_mV{0};
    int64_t i=1;
    while(pV.back()<=1e9 || mV.back()>=-1e9){
        pV.push_back(pow(4,i));
        sum_pV.push_back(pow(4,i)+sum_pV.back());
        mV.push_back(-2*pow(4,i-1));
        sum_mV.push_back(2*pow(4,i-1)+sum_mV.back());
        i++;
    }

    string ans;
    rep(i,0,33) ans+='0';
    while(N!=0){
        if(N>0){
            auto itr=lower_bound(ToEnd(sum_pV),N);
            int d=distance(sum_pV.begin(),itr);
            N-=pV.at(d);
            ans.at(ans.size()-2*d-1)='1';
        }else{
            auto itr=lower_bound(ToEnd(sum_mV),-N);
            int d=distance(sum_mV.begin(),itr);
            N-=mV.at(d);
            ans.at(ans.size()-2*d)='1';
        }
    }

    while(ans.front()=='0') ans.erase(0,1);

    cout<<ans<<endl;
}