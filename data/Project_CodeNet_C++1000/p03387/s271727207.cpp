#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int cnt = 0;
    vector<int> a(3);
    rep(i,3) cin >> a[i];
    sort(a.begin(),a.end());
    //p(a);
    while(a[1] > a[0]){
        a[0] += 2;
        cnt++;
        sort(a.begin(),a.end());
        
    }
    //p(a);
    while(a[2] > a[1]){
        a[1]++;
        a[0]++;
        cnt++;
        sort(a.begin(),a.end());
    }
    //p(a);
    cout << cnt << endl;
}