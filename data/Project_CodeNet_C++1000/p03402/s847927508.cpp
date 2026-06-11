#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;

int main(){
    int A,B;cin>>A>>B;
    vector<string> S(100,"");
    for(int i=0;i<50;++i){
        for(int j=0;j<100;++j){
            S[i]+='.';
            S[50+i]+='#';
        }
    }
    A--;B--;
    int i=0,j=0;
    while(B--){
        S[i][j]='#';
        j+=2;
        if(j>=100){
            j=0;
            i+=2;
        }
    }
    i=51;j=0;
    while(A--){
        S[i][j]='.';
        j+=2;
        if(j>=100){
            j=0;
            i+=2;
        }
    }
    cout<<100<<' '<<100<<endl;
    for(int i=0;i<100;++i){
        cout<<S[i]<<endl;
    }
    return 0;
}