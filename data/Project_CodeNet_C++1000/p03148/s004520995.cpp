#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
using P=pair<int,int>;
using ll=long long;
int main(){
    int n,k;
    cin>>n>>k;
    vector<P> dt(n);
    for(int i=0;i<n;i++){
        cin>>dt[i].second>>dt[i].first;
        dt[i].second--;
    }
    sort(dt.begin(),dt.end(),greater<>());
    ll ret=0,each=0,kind=0;
    vector<bool> used(n,false);
    stack<int> p;
    queue<int> q;
    for(int i=0;i<k;i++){
        if(used[dt[i].second])p.push(i);
        else {
            used[dt[i].second]=true;
            kind++;
        }
        each+=dt[i].first;
    }
    for(int i=k;i<n;i++){
        if(used[dt[i].second]==false){
            q.push(i);
            used[dt[i].second]=true;
        }
    }
    ret=each+kind*kind;
    while(!p.empty()&&!q.empty()){
        int pp=p.top(),qq=q.front();
        p.pop();
        q.pop();
        each-=dt[pp].first;
        each+=dt[qq].first;
        kind++;
        ret=max(ret,each+kind*kind);
    }
    cout<<ret<<endl;
}