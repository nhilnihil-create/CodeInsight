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
#define INF 1100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;



int main(){
    vector<P> ans;
    int N;
    cin>>N;
    ll a[60],temp=0,x;
    for(int i=0;i<N;i++){
        cin>>a[i];
        if(abs(a[i])>temp){
            temp=abs(a[i]);
            x=i;
        }
    }
    cout<<(N-1)+(N-1)<<endl;
    for(int i=0;i<N;i++){
        if(i==x) continue;
        cout<<x+1<<" "<<i+1<<endl;
    }
    if(a[x]<0){
        for(int i=N;i>=2;i--) cout<<i<<" "<<i-1<<endl;
    }else{
        for(int i=1;i<=N-1;i++) cout<<i<<" "<<i+1<<endl;
    }

}
