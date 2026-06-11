#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//using ll = long long;
void p(vector<int> A){rep(i,A.size()){cout << A[i] << " ";}cout << "\n";}

int main(){
    int a, b ,k;
    cin >> a >> b >> k;
    for(int i = a;i <= min(a+k-1,b); i++)cout << i << endl;
    for(int i = max(a+k,b-k+1);i <= b; i++)cout << i << endl;
}