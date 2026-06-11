#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n;
    cin >> n;
    double sum = 0;
    rep(i,n) {
        double x;
        string u;
        cin >> x >> u;
        if(u=="JPY") {
            sum += x;
        } else {
            sum += x*380000;
        }
    }
    printf("%.5f",sum);
    printf("\n");

}