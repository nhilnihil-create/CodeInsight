#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
ll MOD=1000000007;
int inf=1000000000;
ll INF=10000000000000000;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> e(n+1,vector<int>(0));
    vector<int> a(n+1,0),d(n+1,0);
    queue<pp> q;
    rep(i,n-1){
        int f,g;
        cin >> f >> g;
        e.at(f).push_back(g);
        e.at(g).push_back(f);
        a.at(f)++;
        a.at(g)++;
    }
    rep(i,n+1){
        if (a.at(i)==1){
            q.push(make_pair(i,1));
            a.at(i)=-1;
            d.at(i)=1;
        }
    }
    int ans;
    while (!q.empty()){
        int r=q.front().first,t=q.front().second;
        a.at(r)=-1;
        //cout << r << " " << t << endl;
        q.pop();
        rep(i,e.at(r).size()){
            a.at(e.at(r).at(i))--;
            if (a.at(e.at(r).at(i))==1){
                d.at(e.at(r).at(i))=t+1;
                q.push(make_pair(e.at(r).at(i),t+1));
            }
            if (a.at(e.at(r).at(i))==0){
                ans=d.at(r)+d.at(e.at(r).at(i));
                //cout << ans << endl;
            }
        }
    }
    if (ans%3==2) cout << "Second" << endl;
    else cout << "First" << endl;
    //cout << ans << endl;
}