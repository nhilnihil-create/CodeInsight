#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];

    bool is[4] = {};
    rep(i, 4){
        if(a[i]==1)is[0]=true;
        else if(a[i]==9)is[1]=true;
        else if(a[i]==7)is[2]=true;
        else if(a[i]==4)is[3]=true;
        else{
            cout << "NO\n";
            return 0;
        }
    }
    if(is[0]&is[1]&is[2]&is[3])cout << "YES\n";
    else cout << "NO\n";
}
