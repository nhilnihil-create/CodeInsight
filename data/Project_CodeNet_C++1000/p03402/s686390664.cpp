#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    int a,b;cin >> a >> b;
    vector<vector<char>> grid(100,vector<char>(100));
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(j<50) grid[i][j]='.';
            else grid[i][j]='#';
        }
    }
    int needa=a-1;
    int needb=b-1;
    for(int i=0;i<100;i++){
        if(i%2==0) continue;
        for(int j=0;j<100;j++){
            if(j<49){
                if(needb>0&&j%2==1){
                    grid[i][j]='#';
                    needb--;
                }
            }
            else if(j>=51&&j<=98){
                if(needa>0&&j%2==1){
                    grid[i][j]='.';
                    needa--;
                }
            }
        }
    }
    cout << 100 << " " << 100 << endl;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            cout << grid[i][j]; 
        }
        cout << endl;
    }
    return 0;
}