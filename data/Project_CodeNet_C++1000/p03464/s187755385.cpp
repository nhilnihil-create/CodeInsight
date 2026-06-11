#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
const int inf=1e9+7;
const ll mod=1e9+7;

int main() {
    int K;
    cin>>K;
    ll A[K];
    for(int i=0;i<K;++i){
        cin>>A[i];
    }
    ll l = 1, r = 1e15; 
    ll m;
    ll ansmin, ansmax;
    while(l<r){
        m = (l+r)/2;
        for(int i=0;i<K;++i){
            m -= m % A[i];
        }
        if(m>=2){
            r = (l+r)/2;
        }
        else{
            l = (l+r)/2+1;
        }
    }
    ansmin = l;
    l = 1, r = 1e15; 
    while(l<r){
        m = (l+r)/2;
        for(int i=0;i<K;++i){
            m -= m % A[i];
        }
        if(m>2){
            r = (l+r)/2;
        }
        else {
            l = (l+r)/2+1;
        }
    }
    ansmax = l - 1;
    if(ansmax<ansmin)cout<<-1<<endl;
    else cout<<ansmin<<" "<<ansmax<<endl;
}

