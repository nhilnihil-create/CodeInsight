#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define SORT(s) sort((s).begin(),(s).end())

vector<int> enum_div(int n,int m){
    vector<int> ret;
    FOR(i,1,100){
        if(n%i == 0 && m%i == 0){
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    int A,B,K; cin >> A >> B >> K;
    vector<int> ans;
    ans = enum_div(A,B);
    cout << ans[ans.size()-K] << endl;
}
