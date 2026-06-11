#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <utility>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
using P = pair<int,int>;
using ll = long long;
const int MOD=1e9+7;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    vector<pair<P,P>> ret;
    for(int i=0;i<h;i++){
        for(int j=0;j<w-1;j++){
            if(a[i][j]%2==1){
                a[i][j]--;
                a[i][j+1]++;
                ret.push_back(make_pair(P(i,j),P(i,j+1)));
                cnt++;
            }
        }
    }
    for(int i=0;i<h-1;i++){
        if(a[i][w-1]%2==1){
            a[i][w-1]--;
            a[i+1][w-1]++;
            ret.push_back(make_pair(P(i,w-1),P(i+1,w-1)));
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<ret[i].first.first+1<<" "<<ret[i].first.second+1<<" "<<ret[i].second.first+1<<" "<<ret[i].second.second+1<<endl;
    }
}