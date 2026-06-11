#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int d,g;cin >> d >> g;
    typedef pair<int,int>pair;
    vector<pair>vec;
    int a,b;
    REP(i,d){
        cin >> a >> b;
        vec.push_back(pair(a,b));
    }
    bool flag = true;
    int ans = INF;
    for(int bit=0;bit<(1<<d);bit++){
        int count=0,score=0,num1;
        for(int i=0;i<d;i++){
            flag = true;
            if(bit&(1<<i)){
                count+=vec[i].first;
                score+=(100*(i+1)*vec[i].first);
                score+=vec[i].second;
                flag = false;
            }
            if(flag)num1=i+1;
        }
        if(score<g){
            int num3 = 0;
            while(score<g){
                score += 100*num1;
                count++;
                num3++;
                if(num3==vec[num1-1].first)break;
            }
        }
        if(score<g)continue;
        ans = min(ans,count);
    }
    COUT(ans);
    return 0;
}