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
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll a[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    ll t,cnt,cnt3=0,cnt5=0,cnt15=0,cnt25=0,cnt75=0;
    ll i;
    for(i=0;i<15;i++){
        t=a[i];
        cnt=0;
        while(t<=N){
            cnt+=N/t;
            t*=a[i];
        }
        if(cnt>=2)cnt3++;
        if(cnt>=4)cnt5++;
        if(cnt>=14)cnt15++;
        if(cnt>=24)cnt25++;
        if(cnt>=74)cnt75++;
    }
    ll ans=0;
    ans+=cnt5*(cnt5-1)*(cnt3-2)/2;
    ans+=cnt15*(cnt5-1);
    ans+=cnt25*(cnt3-1);
    ans+=cnt75;
    cout << ans;
    return 0;
}
