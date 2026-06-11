#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define vec(j,n) vector<int>(j(n))
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<int>a(m+1);
    vector<int>ans(n+1,0);
    for(int i=1;i<=m;i++){
        cin >> a.at(i);
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a.at(i) == j){
                ans.at(j) = 1;
            }
        }
    }
    int count1 = 0;
    int count2 = 0;
    for(int i=1;i<=x;i++){
        if(ans.at(i) == 1){
            count1 ++;
        }
    }
    for(int i=x;i<=n;i++){
        if(ans.at(i) == 1){
            count2 ++;
        }
    }
    cout << min(count1,count2) << endl;
    return 0;
}