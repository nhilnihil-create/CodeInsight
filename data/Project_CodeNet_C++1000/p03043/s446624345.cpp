#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define dupl(s) s.erase(unique(s.begin(), s.end()), s.end());//重複取り除き
#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> s){return accumulate(s.begin(),s.end(),0);}
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    double n;
    int k;
    cin >> n >> k;
    double ans = 0;
    for(int i = 1; i <= n; i++){
      int score = i;
      int cnt = 0;
      while(score < k){
        score *= 2;
        cnt++;
      }
      ans += (1/n) * pow(0.5,cnt);
    }
    cout << fixed << setprecision(10) << ans << endl;
}