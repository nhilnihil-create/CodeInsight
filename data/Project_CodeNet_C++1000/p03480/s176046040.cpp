//操作によりT(S)が減ると、その設定したKではすべて0にすることができなくなる
//T(S)が減らないKの値、つまりmax(k, n-k)の内最小の値をKに設定すれば良い
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    int n = S.size();
    int T = S.size();
    for(int i = 0; i < n-1; ++i) {
        if(S[i] != S[i+1]) 
            T = min(T, max(i+1, n - i - 1));
    }
    cout << T << endl;
    return 0;
}