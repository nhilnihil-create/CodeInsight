#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
char s[100][100];
int h,w;
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1,0,0,1,1,1};

int bomb(int i,int j){
    if(s[i][j]=='#'){
        return -1;
    }
    int res=0;
    for(int x=0;x<8;x++){
        if(i+dy[x]>=0 && i+dy[x]<h && j+dx[x]>=0 && j+dx[x]<w && s[i+dy[x]][j+dx[x]]=='#') res++;
    }
    return res;
}

int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char a;
            cin>>a;
            s[i][j]=a;
        }
    }
    vector<vector<int> > ans(h,vector<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            ans[i][j]=bomb(i,j);
        }
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(ans[i][j]==-1){
                cout<<'#';
            }else{
                cout<<ans[i][j];

            }
        }
        cout<<endl;
    }

}