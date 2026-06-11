#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll cnt[13];
ll used[24];

int main(void){
    int n,d;
    int ans=0,num=24;
    cin>>n;
    cnt[0]++;
    for(int i=0;i<n;i++){
        cin>>d;
        cnt[d]++;
    }
    for(int i=0;i<(1<<11);i++){
        num=24;
        for(int j=0;j<24;j++)used[j]=false;
        for(int j=0;j<13;j++){
            if(cnt[j]==0)continue;
            if(j==0 || j==12){
                used[j]=true;
                if(cnt[j]>=2)num=0;
            }
            else{
                if(cnt[j]>=3)num=0;
                else{
                    if(cnt[j]==2){
                        used[j]=true;
                        used[24-j]=true;
                    }
                    else{
                        used[i&(1<<(j-1))?j:24-j]=true;
                    }
                }
            }
        }
        for(int i=0;i<23;i++){
            for(int j=0;j<23;j++){
                if(i==j)continue;
                if(used[i]&used[j]){
                    int x=i-j;
                    if(x<0)x*=-1;
                    num=min(num,min(x,24-x));
                }
            }
        }
        ans=max(ans,num);
    }
    cout<<ans<<endl;
    return 0;
}