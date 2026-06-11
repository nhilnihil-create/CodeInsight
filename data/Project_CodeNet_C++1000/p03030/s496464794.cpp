#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n;cin >>n;
    vector<pair<string,int>>a(n);
    vector<pair<string,int>>b(n);
    for (int i = 0; i < n; ++i) {
        string s;cin >>s;
        int p;cin >>p;
        a[i]={s,-p};
        b[i]={s,-p};
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i]==b[j]){
                cout <<j+1<<endl;
            }
        }
    }
    return 0;
}
