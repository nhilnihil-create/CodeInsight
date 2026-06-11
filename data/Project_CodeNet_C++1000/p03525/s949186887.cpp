#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
#include<map>
#include<set>
#include <climits>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;

int D[20],s[30];
vector<int> v;

void reset(){
    for(int i=0;i<30;i++) s[i]=0;
    for(int i=0;i<(int)v.size();i++){
        s[v[i]]++;
    }
    s[0]++;
    s[24]++;
}


int main(){
    int N,a,ans=0;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>a;
        D[a]++;
    }

    D[0]++;

    for(int i=0;i<=12;i++){
        if(i==0 && D[i]>=2 || i==12 && D[i]>=2 || D[i]>=3){
            cout<<0<<endl;
            return 0;
        }else if(D[i]==2){
            v.push_back(i); v.push_back(24-i);
            D[i]=0;
        }
    }

    reset();

    for(int bit=0;bit< (1<<13); bit++,reset()){
        for(int i=0;i<13;i++){
            if(D[i]==0) continue;
            if(bit>>i & 1){
                s[24-i]++;
            }else{
                s[i]++;
            }
        }
        int temp=0,ss=100;
        for(int i=1;i<=24;i++){
            if(s[i]){
                ss=min(i-temp,ss);
                temp=i;
            }
        }
        ans=max(ans,ss);
    }
    cout<<ans<<endl;
}