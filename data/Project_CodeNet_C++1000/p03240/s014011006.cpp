#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //GCC5.4.1で配列の範囲外アクセスをエラーにする

//cmdで g++ test.cpp とするとコンパイルできる
//制限1秒なら10^6は余裕 10^7は多分間に合う 10^8はよほど単純でないと厳しい

#define ALL(x) x.begin(),x.end()
#define get_tp(t,i) get<i>(t)
typedef long long ll; //long long
typedef pair<int,int> pii; //pair<int,int>
typedef pair<long long,long long> pllll; //pair<ll,ll>
typedef vector<int> vi; //vector<int>
typedef vector<vector<int>> vvi; //vector<vector<int>>
typedef vector<ll> vll; //vector<long long>
typedef vector<vector<ll>> vvll; //vector<vector<long long>>
typedef priority_queue<int, vector<int>, greater<int> > gpq; //逆順priority_queue
typedef priority_queue<int> pq;

//const int MOD=998244353;
const int MOD=1000000007; //10^9+7
const long double PI=3.1415926535897932;

int main(){
    int N;
    cin>>N;
    vector<tuple<int,int,int>> d(N);
    for(int i=0;i<N;i++){
        int x,y,h;
        cin>>x>>y>>h;
        d[i]=make_tuple(h,x,y);
    }
    sort(ALL(d));
    reverse(ALL(d));
    
    for(int cx=0;cx<=100;cx++){
        for(int cy=0;cy<=100;cy++){
            int height=get_tp(d[0],0)+abs(get_tp(d[0],1)-cx)+abs(get_tp(d[0],2)-cy);
            bool ok=true;
            for(int i=1;i<N;i++){
                if(get_tp(d[i],0)!=max(0,height-abs(get_tp(d[i],1)-cx)-abs(get_tp(d[i],2)-cy))){
                    ok=false;break;
                }
            }
            if(ok){
                cout<<cx<<" "<<cy<<" "<<height<<endl;return 0;
            }
        }
    }
    
    
}