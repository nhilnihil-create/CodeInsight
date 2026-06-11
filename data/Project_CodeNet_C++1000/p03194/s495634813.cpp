#include <iostream>
#include <string>
#include <algorithm> 
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <limits>
#define ll long long
using namespace std;
int main(){
    ll N,P,h;
    cin >> N >> P;
    ll a=P;
    ll count=0,ans=-1,answer=1;
    for(ll i=2;i<1000005;i++){
        while(1){
            if(P%i==0){
                P = P / i;
                count++;
                if(count>=N){
                answer = i * answer;
                count=0;
                }
            }else{
                break;
            }
        }
        count=0;
    }
    if(N==1){
        cout << a << endl;
    }else if(a==1){
        cout << 1 << endl;
    }else{
        cout << answer << endl;
    }
}