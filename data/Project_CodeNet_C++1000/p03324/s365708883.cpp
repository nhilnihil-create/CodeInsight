#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<int> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    int d, n;
    cin >> d >> n;
    if (n == 100)printf("%d",101*(int)pow(100,d));
    else cout << n*pow(100,d);
}