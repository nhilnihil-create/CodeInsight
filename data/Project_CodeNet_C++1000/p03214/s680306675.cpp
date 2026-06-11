#include <bits/stdc++.h>
using namespace std;
int main(){
    //write code  here
    int N;
    cin >> N;
    vector<int>a(N);

    int sum=0;

    for (int i = 0; i < N; ++i) {
        cin >> a.at(i);
        sum += a.at(i);

    }
    float var = (float)sum / (float)N;
    vector<float>disFromSum(N);
    float minDis = (float) N;
    int flame = N;
    for (int i = 0; i < N; ++i) {
        disFromSum.at(i) = var - a.at(i);//差を計算
        if (disFromSum.at(i) < 0) disFromSum.at(i) *= -1;//絶対値
        if (disFromSum.at(i) < minDis){
            minDis = disFromSum.at(i);//最小値を更新
            flame = i;//フレームを選択
        }
    }
    cout << flame << endl;

    return 0;
}