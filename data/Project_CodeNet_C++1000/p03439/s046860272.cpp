#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

bool is(ll x, ll y, string a, string b){
    if((y-x)&1)return a == b;
    else return a != b;
}
int main(){
    ll n;
    string l, r;
    cin >> n;
    ll left = 0, right = n-1;
    cout << left << endl << flush;
    cin >> l;
    cout << right << endl << flush;
    cin >> r;
    if(l=="Vacant" || r=="Vacant")return 0;
    ll in;
    left++;
    rep(i, 18){
        in = (right + left)/2;
        cout << in << endl << flush;
        string ins;
        cin >> ins;
        if(ins=="Vacant")return 0;
        if(is(left, in-1, ins, l))right=in-1, r=ins;
        else left=in+1, l=ins;
    }
    return 0;
}