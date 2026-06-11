#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<functional>
#include<map>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define PII pair<int,int>
#define PLI pair<long long, int>
#define MOD ((int)1e9 + 7)
#define INF ((int)1e9)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define ctoi(x) (x - 'a') 
#define CTOI(x) (x - 'A')
#define BIT(x) (1 << (x))
using namespace std;
int main(){
    double ans = 0;
    int N;
    cin >> N;
    vector<int> times(N+2), velocitys(N+2), safe(N+2), sumtimes(N+2);
    times[0]=velocitys[0]=sumtimes[0]=0;
    times.back()=velocitys.back()=0;
    REPA(i, N+1){
        cin>>times[i];
    }
    REPA(i, N+1){
        cin >> velocitys[i];
    }
    ++N;
    REPA(i, N+1){
        sumtimes[i]=sumtimes[i-1]+times[i];
        safe[i]=sumtimes[i-1]+velocitys[i];
    }
    double nowtime=0;
    double nowspeed=0;
    while(nowtime<sumtimes.back()){
        double ns = nowspeed+0.5;
        REPA(i, N+1){
            if(sumtimes[i-1] > nowtime && safe[i] < nowtime+0.5+ns){
                ns-=0.5;
                break;
            }
            if(sumtimes[i-1]<=nowtime&&nowtime<sumtimes[i]){
                if(ns > velocitys[i]){
                    ns-=0.5;
                    break;
                }
            }
        }
        REPA(i, N+1){
            if(sumtimes[i-1] > nowtime && safe[i] < nowtime+0.5+ns){
                ns-=0.5;
                break;
            }
            if(sumtimes[i-1]<=nowtime&&nowtime<sumtimes[i]){
                if(ns > velocitys[i]){
                    ns-=0.5;
                    break;
                }
            }
        }
        ans+=(ns+nowspeed)*0.25;
        nowtime+=0.5;
        nowspeed=ns;
    }
    printf("%.10f\n", ans);
    return 0;
}
