#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>>data(m);//0=pref,1=year,2=order
    rep(i,m){
        cin>>get<0>(data[i])>>get<1>(data[i]);
        get<2>(data[i])=i;
    }
    sort(data.begin(),data.end());
    int cnt=0;
    rep(i,m){//1 to order in pref
        if(i==0||get<0>(data[i])==get<0>(data[i-1])){
            cnt++;
            get<1>(data[i])=cnt;
        }
        else{
            cnt=1;
            get<1>(data[i])=cnt;
        }
    }
    char c1,c2;
    vector<tuple<int,string,string>>ans(m);//0=order,1=prefnum,2=inprefnum
    rep(i,m){
        get<0>(ans[i])=get<2>(data[i]);
        rep(j,6){
            c1='0'+get<0>(data[i])%10;
            c2='0'+get<1>(data[i])%10;
            get<1>(ans[i])=c1+get<1>(ans[i]);
            get<2>(ans[i])=c2+get<2>(ans[i]);
            get<0>(data[i])/=10;
            get<1>(data[i])/=10;
        }
    }
    sort(ans.begin(),ans.end());
    rep(i,m){
        cout<<get<1>(ans[i])<<get<2>(ans[i])<<endl;
    }
	return 0;
}
