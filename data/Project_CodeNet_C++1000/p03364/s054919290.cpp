#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
#include<tuple>
using namespace std;
#define INF 11000000000
#define MAX 5100
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
const double PI = acos(-1);

int main(){
    int N;
    cin>>N;
    char S[310][310],temp[310][310];
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>S[i][j];
    }
    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                temp[(j+i)%N][k]=S[j][k];
            }
        }
        bool flag=true;
        for(int j=1;j<N;j++){
            for(int k=0;k<j;k++){
                if(temp[j][k]!=temp[k][j]) flag=false;
            }
        }
        if(flag) ans+=N;
    }
    cout<<ans<<endl;
}

