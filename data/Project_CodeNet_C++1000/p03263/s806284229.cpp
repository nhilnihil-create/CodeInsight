#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<pair<pair<int,int>, pair<int,int>>> ans;
int main(){
    cout << fixed << setprecision(10);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> v(h,vector<int>(w));
    rep(i,h) rep(j,w) cin >> v[i][j];
    int i = 0, j = 0;
    int itr = 0;
    while(itr < h*w){
        if(v[i][j] & 1){
            int ni = i, nj = j;
            if(ni % 2 == 0){
                if(nj < w-1) nj++;
                else ni++;
            }else{
                if(nj > 0) nj--;
                else ni++; 
            }
            if( ni < h && nj < w){
                ans.push_back(make_pair(make_pair(i+1,j+1),make_pair(ni+1,nj+1)));
                v[ni][nj] ++;
            }
            i = ni, j = nj;
            itr++;
        }else{
            int ni = i, nj = j;
            if(ni % 2 == 0){
                if(nj < w-1) nj++;
                else ni++;
            }else{
                if(nj > 0) nj--;
                else ni++;  
            }
            i = ni, j = nj;
            itr++;           
        }
    }
    cout << ans.size() << endl;
    for(auto u : ans){
        cout << u.first.first << " " << u.first.second << " " << u.second.first << " " << u.second.second << endl;
    }
    return 0;
}