#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0;
vector<ll> A;

signed main(){
    cin >> N;
    if(N==3) {
        cout << " " << 2;
        cout << " " << 5;
        cout << " " << 63;
        return 0;
    }
    if(N==4) {
        cout << " " << 2;
        cout << " " << 5;
        cout << " " << 20;
        cout << " " << 63;
        return 0;
    }
    ans = N/8;
    ans *= 8;
    tmp = N%8;
    ll ct=0;
    A.push_back(0);
    if(ct<ans) {
        for(int i=2;i<=30000;i++) {
            if(i%2==0||i%3==0) {
                A.push_back(i);
                ct++;
                if(ct==ans) break;
            }
        }
    }
    if(tmp<0) tmp += 8;
    ll num = A.back();
    if(tmp==1) {
        A.push_back(num+6);
    }
    if(tmp==2) {
        A.push_back(num+6);
        A.push_back(num+12);
    }
    if(tmp==3) {
        A.push_back(num+3);
        A.push_back(num+6);
        A.push_back(num+9);
    }
    if(tmp==4) {
        A.push_back(num+3);
        A.push_back(num+6);
        A.push_back(num+9);
        A.push_back(num+12);
    }
    if(tmp==5) {
        A.push_back(num+2);
        A.push_back(num+3);
        A.push_back(num+4);
        A.push_back(num+9);
        A.push_back(num+12);
    }
    if(tmp==6) {
        A.push_back(num+2);
        A.push_back(num+3);
        A.push_back(num+4);
        A.push_back(num+6);
        A.push_back(num+9);
        A.push_back(num+12);
    }
    if(tmp==7) {
        A.push_back(num+2);
        A.push_back(num+3);
        A.push_back(num+4);
        A.push_back(num+6);
        A.push_back(num+8);
        A.push_back(num+9);
        A.push_back(num+10);
    }
    for(int i=1;i<A.size();i++) {
        cout << " " << A[i];
    }
    return 0;
}