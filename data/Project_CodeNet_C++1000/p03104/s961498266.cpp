#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MOD=1000000007;

int main(){
    ll A,B;
    cin>>A>>B;
    ll ans=0;
    ll a=A%4;
    ll b=B%4;
    if(a+1==b || (a==b && (a==1 || a==3)) || (a==0 && b==2) || (a==2 && b==0) || (a==3 && b==0)){
        ans++;
    }else{
        ans=0;
    }
    int i=1;
    while(pow(2,i)<=max(A,B)){
        ll a=A%(ll)pow(2,i+1);
        ll b=B%(ll)pow(2,i+1);
        if(b>=a){
            if(b>=pow(2,i) && a<pow(2,i)){
                if((b-(ll)pow(2,i)+1)%2==1){
                    ans+=pow(2,i);
                }
            }else if(a<pow(2,i) && b<pow(2,i)){
                i++;
                //cout<<a<<","<<b<<" "<<ans<<endl;
                continue;
            }else{
                if((b-a)%2==0){
                    ans+=pow(2,i);
                }
            }
        }else{
            if(b<pow(2,i) && a>=pow(2,i)){
                if(((ll)pow(2,i+1)-a)%2==1){
                    ans+=pow(2,i);
                }
            }else if(a<pow(2,i) && b<pow(2,i)){
                i++;
                //cout<<a<<","<<b<<" "<<ans<<endl;
                continue;
            }else{
                if((a-b)%2==0){
                    ans+=pow(2,i);
                }
            }
        }
        //cout<<a<<","<<b<<" "<<ans<<endl;
        i++;
    }
    cout<<ans<<endl;
}