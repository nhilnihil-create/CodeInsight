#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};

#define rep(i,x) for(int i=0;i<x;i++)
#define re(i,x,y) for(int i=x;i<y;i++)

long long INF=1e9;
const int mod=10007;
#define ll long long

int main(){
    string n;
    cin>>n;
    if(n.size()==2){
        rep(i,n.size()){
            cout<<n[i];
        }
    }else if(n.size()==3){
        for(int i=n.size()-1;i>=0;i--){
            cout<<n[i];
        }
    }
    return 0;
}
