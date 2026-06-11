#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep_1(i,n) for(int (i)=0;(i)<=(n);(i)++)
#define rep_2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main(){
    int n;cin>>n;
    vector<int> a(n);
    double sum = 0;
    rep(i,n){
        cin >>a[i];
        sum+=a[i];
    }
    double ave = sum/(double)n;

    int ans = 0;
    double mn = INF;
    int pos = 0;
    rep(i,n){
        double dx = abs(ave-a[i]);
        if(mn>dx) {
            mn = dx;
            pos = i;
        }

    }
    cout << pos <<endl;

}

