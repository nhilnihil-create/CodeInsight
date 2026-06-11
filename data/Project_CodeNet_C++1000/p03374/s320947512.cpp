
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    stringstream ss;
    // 入力
    int N;
    ll C;

    cin>>N>>C;
    ll x[N];
    ll v[N];
    for(int i=0;i<N;i++){
        cin>>x[i]>>v[i];
    }
    ll calL[N];
    ll calR[N];
    ll calLmax[N];
    ll calRmax[N];
    ll calLmaxval=0;
    ll calRmaxval=0;
    int calLmaxid=0;
    int calRmaxid=0;
    int calLid[N];
    int calRid[N];

    ll cal=0;
    ll calmax=0;
    calL[0]=v[0]-x[0];
    calR[0]=v[N-1]-(C-x[N-1]);
    calLmaxval=calL[0];
    calLmax[0]=calL[0];
    calRmaxval=calR[0];
    calRmax[0]=calR[0];
    calLid[0]=0;
    calRid[0]=0;
    for(int i=1;i<N;i++){
        calL[i]=calL[i-1]+v[i]-(x[i]-x[i-1]);
        calR[i]=calR[i-1]+v[N-i-1]-(x[N-i]-x[N-i-1]);
        if(calLmaxval<calL[i]){
        	calLmaxid=i;
        	calLmaxval=calL[i];
        }
        if(calRmaxval<calR[i]){
        	calRmaxid=i;
        	calRmaxval=calR[i];
        }
        calLmax[i]=calLmaxval;
        calRmax[i]=calRmaxval;
        calLid[i]=calLmaxid;
        calRid[i]=calRmaxid;
    }
    cout<<endl;
    for(int i=0;i<N;i++){
        cal=calL[i];
        if(cal>calmax)calmax=cal;
        cal=calR[i];
        if(cal>calmax)calmax=cal;
    }

    for(int i=0;i<N-1;i++){
    	//cout<<"i="<<i<<": "<<calLmax[i]<<","<<calRmax[N-i-2]<<","<<C-x[N-calRid[N-i-2]-1]<<","<<x[calLid[i]]<<endl;
            if(x[calLid[i]]>C-x[N-calRid[N-i-2]-1]) cal=calLmax[i]+calRmax[N-i-2]-(C-x[N-calRid[N-i-2]-1]);
            else cal=calLmax[i]+calRmax[N-i-2]-x[calLid[i]];
            if(cal>calmax) calmax=cal;
    }
    // cout<<endl;
    cout<<calmax<<endl;
    return 0;
}