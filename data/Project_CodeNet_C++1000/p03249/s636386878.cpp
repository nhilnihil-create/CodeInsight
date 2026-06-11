#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define __DEBUG__
#undef __DEBUG__
#define MAXN 100005

using namespace std;

int main(){
    int N;
    typedef long long ll;
    pair<ll,int> D[MAXN];//D,ソートする前のノードの番号
    pair<int,int> ans[MAXN];
    int Chi[MAXN];
    ll Dep[MAXN];//深さの和　木の根でDと一致するはず
    map<ll,int> Ds;//D,ソート後のノードの番号 配列の逆(Dから配列のindexを探しやすくするため)
    map<ll,int>::iterator it;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>D[i].first;
        D[i].second=i+1;
        Chi[i]=1;
        Dep[i]=0;
    }
    sort(D,D+N,greater<pair<ll,int> >());
    for(int i = 0;i < N;i++){
        Ds[D[i].first]=i;
    }
#ifdef __DEBUG__
    cout<<"sorted:"<<endl;
    for(int i = 0;i < N;i++){
        cout<<D[i].first<<","<<D[i].second<<"/";
    }
    cout<<endl;
#endif
    for(int i = 0;i < N-1;i++){
        ll Dj = D[i].first+Chi[i]*2-N;
        if(it = Ds.find(Dj),it==Ds.end()){
            cout<<-1<<endl;
            return 0;
        }
        int j = it->second;
        Chi[j]+=Chi[i];
        Dep[j]+=Dep[i]+Chi[i];
        ans[i]=make_pair(D[i].second,D[j].second);
    }
#ifdef __DEBUG__
    cout<<Dep[N-1]<<endl;
#endif
    if(Chi[N-1]!=N||Dep[N-1]!=D[N-1].first){
        cout<<-1<<endl;
        return 0;
    }
    for(int i = 0;i < N-1;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
