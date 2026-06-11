#include <bits/stdc++.h>
using namespace std;
#define double long double
#define ll long long
#define rep(i,n) for (int i = 0; i < (n); ++i)
const int INF = 100000000;
typedef pair<int,int> P;

vector<int>a;

int main(void){
    int ans=INF;
    int d,g;
    cin>>d>>g;
    vector<int>p(d);
    vector<int>c(d);
    rep(i,d) cin>>p[i]>>c[i];
    for(int bit=0;bit<(1<<d);++bit){
        int sum=0;
        int last=-1;
        int count=0;
        for(int i=0;i<d;i++){
            if(bit&(1<<i)){
            sum+=(i+1)*100*p[i];
            sum+=c[i];
            count+=p[i];
            }else{
                last=i;
            }
        }
        if(sum<g){
            int s=100*(last+1);
            int need=(g-sum+s-1)/s;
            if(need>=p[last]){
                continue;
            }
            count+=need;
        }
        ans=min(ans,count);
    }
    cout<<ans<<endl;
}
