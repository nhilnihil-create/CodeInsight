#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    int N,K;
    cin >> N >> K;
    ll input[N] = {};
    rep0(i,N){
        cin >> input[i];
    }
    sort(input,input+N);
    ll res = pow(10,9)+1;
    rep0(i,N-K+1){
        if(res > input[i+K-1]-input[i]){
            res = input[i+K-1]-input[i];
        }
    }
    cout <<res << endl;
}
