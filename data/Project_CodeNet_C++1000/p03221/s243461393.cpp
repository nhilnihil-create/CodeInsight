#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    
    int n,m;
    cin >> n >> m;
    vector <vector <int>> v(n+1),v2(n+1);
    vector <vector <int>> so;
    vector <vector <int>> ans(m,vector <int> (2));

    int p,y;
    rep(i,m){
        cin >> p >> y;
        v[p].push_back(i);
        v2[p].push_back(y);
        ans[i][0]=p;
    }

    int l;
    rep(i,n){
        l=v[i+1].size();
        so.resize(l);
        rep(j,l){
            so[j].resize(2);
        }
        rep(j,l){
            so[j][0]=v2[i+1][j];
            so[j][1]=v[i+1][j];
        }
        sort(so.begin(),so.end());
        rep(j,l){
            ans[so[j][1]][1]=j+1;
        }
    }
    string s1,s2,s;
    int l1,l2;
    rep(i,m){
        s1=to_string(ans[i][0]);
        s2=to_string(ans[i][1]);
        l1=6-s1.size();
        l2=6-s2.size();
        rep(j,l1){
            s1="0"+s1;
        }
        rep(j,l2){
            s2="0"+s2;
        }
        
        
        cout << s1+s2 << endl;
    }

    

    return 0;
}