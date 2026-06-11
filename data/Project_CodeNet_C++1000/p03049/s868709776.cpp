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
    ll cnt=0;
    int a=0;
    int b=0;
    int ab=0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s.front() == 'B' && s.back() == 'A')ab++;
        else if (s.front() == 'B')b++;
        else if (s.back() == 'A')a++;
        for (int j = 0; j < (int) s.size(); ++j) {
            if (s.substr(j, 2) == "AB")cnt++;
        }
    }
    if(ab>0) {
        cnt += ab - 1;
        if(a>0){
            cnt++;
            a--;
        }
        if(b>0){
            cnt++;
            b--;
        }
    }
    cnt+=min(a,b);
    cout <<cnt<<endl;
}
