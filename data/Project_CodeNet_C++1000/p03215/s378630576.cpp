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
    ll a[1100],K;
    cin>>N>>K;
    for(int i=0;i<N;i++) cin>>a[i];

    vector<ll> V,ans[50];
    for(int i=0;i<N;i++){
        ll temp=0;
        for(int j=0;i+j<N;j++){
            temp+=a[i+j];
            V.push_back(temp);
            ans[0].push_back(temp);
        }
    }
    int t=45;
    ll x=1;
    while(t--){
        x*=2;
    }
    bool hantei[1100000];
    ll ret=0;
    for(int i=0;x!=0;i++,x/=2){
        int count=0;
        for(int j=0;j<(int)ans[i].size();j++){
            if(ans[i][j]>=x){
                ans[i][j]-=x;
                count++;
                hantei[j]=true;
            }else hantei[j]=false;
        }
        if(count>=K){
            ret+=x;
            for(int j=0;j<(int)ans[i].size();j++){
                if(hantei[j]) ans[i+1].push_back(ans[i][j]);
            }
        }else{
            for(int j=0;j<(int)ans[i].size();j++){
                ans[i+1].push_back(ans[i][j]);
            }
        }


    }
    cout<<ret<<endl;
}

