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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
char s[100][100];
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};

int main(){
    int h,w;
    cin>>h>>w;
    for(int i=0;i<100;i++){
        s[0][i]='.';
        s[h+1][i]='.';
        s[i][w+1]='.';
        s[i][0]='.';
    }
    for(int j=1;j<=h;j++){
        for(int i=1;i<=w;i++){
            cin>>s[j][i];
        }
    }
    /*for(int j=0;j<=h+1;j++){
        for(int i=0;i<=w+1;i++){
            cout<<s[j][i];
        }
        cout<<endl;
    }*/
    for(int j=1;j<=h;j++){
        for(int i=1;i<=w;i++){
            bool f=false;
            if(s[j][i]=='#'){
                for(int v=0;v<4;v++){
                    if(s[j-dy[v]][i-dx[v]]=='#') f=true;
                }
                if(!f){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}