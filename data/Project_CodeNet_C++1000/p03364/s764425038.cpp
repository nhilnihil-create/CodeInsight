#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 10000000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;


int main(){
    bool flag=true;
    int N,ans=0,x,y;
    cin>>N;
    string s[310];
    for(int i=0;i<N;i++){
        cin>>s[i];
    }

    for(int i=0;i<N;i++,flag=true){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(s[j][(k+i)%N]!=s[k][(j+i)%N]) flag=false;
            }
        }
        //cout<<flag<<endl;
        if(flag) ans++;
    }
    cout<<ans*N<<endl;
}
