#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    //dp_min[i] : 後ろからi番目をYが引いた時の|X-Y|の最小値
    //dp_max[i] : 後ろからi番目をXが引いた時の|X-Y|の最大値
    vector<int> dp_min(N+1), dp_max(N+1);
    dp_min[1] = 1e9;
    dp_max[1] = abs(a[N-1]-W);
    for(int i = 2; i < N+1; ++i) {
        dp_min[i] = abs(a[N-i] - a[N-1]);
        dp_max[i] = abs(a[N-i] - a[N-1]);
        for(int j = 1; j < i; ++j) {
            dp_min[i] = max(dp_min[i], dp_max[j]); //後ろからi番目をYが選んだらXはそれ以降で最もスコアが最大になるマスを選ぼうとする
            dp_max[i] = min(dp_max[i], dp_min[j]); //後ろからi番目をXが選んだらYはそれ以降で最もスコアが最小になるマスを選ぼうとする
        }
    }
    
    cout << *max_element(dp_max.begin(), dp_max.end()) << endl;
    return 0;
}