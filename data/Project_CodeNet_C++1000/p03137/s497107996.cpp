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
    int N, M;
    cin >> N >>  M;
    vector<int> input(M);
    rep0(i,M){
        cin >> input[i];
    }
    sort(input.begin(),input.end());
    vector<int> diff(M-1);
    for(int i = 0;i<M-1;i++){
        diff[i]=input[i+1]-input[i];
    }
    sort(diff.begin(),diff.end());
    ll res = 0;
    rep0(i,M-N){
        res += diff[i];
    }
    cout << res << endl;
}
