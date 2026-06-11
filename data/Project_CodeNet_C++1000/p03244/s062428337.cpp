#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,k;
    cin >> n;
    vector <vector <int>> s(100001,vector <int> (2,0)),s2(100001, vector <int> (2,0));
    rep(i,n){
        cin >> k;
        if(i%2==0){
            ++s2[k][0];
        }
        else{
            ++s[k][0];
        }
    }

    rep(i,100001){
        s[i][1]=i;
        s2[i][1]=i;
    }

    sort(s2.begin(),s2.end());
    sort(s.begin(),s.end());
    int ans;
    if(s[100000][1]==s2[100000][1]){
        ans=max(s[100000][0]+s2[99999][0],s[99999][0]+s2[100000][0]);
    }
    else{
        ans=s[100000][0]+s2[100000][0];
    }

    cout << n-ans << endl;
    
    

    return 0;
}