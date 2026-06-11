#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
void pulse(pair<int,int>& a){
    a.first++;a.second++;
}
struct Ans{
int no;
vector<pair<int,int>> tree;
vector<pair<int,int>> next_tree(){
    vector<pair<int,int>> next=tree;
    int n=tree.size();
    rep(i,n)pulse(next[i]);
    for(int i=2;i<=no+1;i++){
        next.push_back(make_pair(1,i));
        next.push_back(make_pair(i,no+2));
    }
    return next;
}
void output(){
int n=tree.size();
cout<<n<<endl;
rep(i,n){
    cout<<tree[i].first<<" "<<tree[i].second<<endl;
}
}
};

signed main(){
    int n;cin>>n;
    vector<Ans> ans(105);
    ans[3].tree.push_back(make_pair(1,3));
    ans[3].tree.push_back(make_pair(2,3));
    ans[4].tree.push_back(make_pair(1,2));
    ans[4].tree.push_back(make_pair(1,3));
    ans[4].tree.push_back(make_pair(2,4));
    ans[4].tree.push_back(make_pair(3,4));
    rep(i,n+1)ans[i].no=i;
    for(int i=4;i<=100;i+=2){
        vector<pair<int,int>> next=ans[i].next_tree();
        ans[i+2].tree=next;
    }
    for(int i=5;i<=100;i+=2){
        vector<pair<int,int>> next=ans[i-1].tree;
        rep1(j,i-1)next.push_back(make_pair(j,i));
        ans[i].tree=next;
    }
    ans[n].output();
    return 0;
}