#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N,C;
    ll s,t,c;
    ll i,j;
    cin >> N >> C;
    ll ch[C][100010];
    for(i=0;i<C;i++){
        for(j=0;j<100010;j++){
            ch[i][j]=0;
        }
    }
    for(i=0;i<N;i++){
        cin >> s >> t >> c;
        ch[c-1][s]+=1;
        ch[c-1][t+1]-=1;
    }
    ll tmp=0,ans=0;
    for(j=1;j<100010;j++){
        for(i=0;i<C;i++){
            ch[i][j]+=ch[i][j-1];
        }
    }
    for(j=0;j<100010;j++){
        tmp=0;
        for(i=0;i<C;i++){
            if(ch[i][j]!=0)tmp++;
        }
        ans=max(ans,tmp);
    }
    cout << ans;
    return 0;
}
