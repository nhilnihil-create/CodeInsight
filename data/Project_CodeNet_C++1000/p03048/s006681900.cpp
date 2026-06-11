#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int r, g, b ,n;
    cin >> r >> g >> b >> n;
    int cnt = 0;
    rep(i,n+1){
        rep(j,n+1){
            int k = n - r*i - g*j;
            if(k % b == 0 && k >= 0){
                cnt++;
            }
        }
    }
    cout << cnt;
}