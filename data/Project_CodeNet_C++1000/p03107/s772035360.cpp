#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}
void print(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << endl;}

int main(){
    string s;
    cin >> s;
    int cnt1 = 0,cnt2 = 0;
    rep(i,s.size()){
        if (s[i] == '1')cnt1++;
        else cnt2++;
    }
    cout << 2*min(cnt1,cnt2) << endl;
}