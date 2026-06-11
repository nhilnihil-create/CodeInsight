#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<ll> vec(N+1,0);
    map<ll,ll> m;
    m[0]=1;
    for(int i=0; i<N; i++){
        ll a;
        cin >> a;
        vec[i+1]=vec[i]+a;
        if(m.count(vec[i+1])){
            m[vec[i+1]]++;
        }else{
            m[vec[i+1]]=1;
        }
    }

    ll ans=0;
    for(auto it=m.begin(); it!=m.end(); it++){
        ans+=(it->second)*((it->second)-1)/2;
    }
    cout << ans << endl; 
}