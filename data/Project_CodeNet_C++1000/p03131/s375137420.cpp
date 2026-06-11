#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i = 1; i <= x; i++)
#define SORT(x) sort(x.begin(),x.end())
#define dupl(s) s.erase(unique(s.begin(), s.end()), s.end());//重複取り除き
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    long long k,a,b;
    cin >> k >> a >> b;
    if(b - a <= 2 || k < a - 1)cout << k + 1;
    else{
        long long ans = a;
        k -= a - 1; 
        if(k % 2 == 1)k--,ans++;
        ans += (b - a)*(k/2);
        cout << ans;
    }
}