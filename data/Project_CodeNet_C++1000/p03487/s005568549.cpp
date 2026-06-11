
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    //mapのキーには出てきた数字が何か、値にはそれが何回出現したかを記録する
    map<int,int> m;
    //範囲for文の変数前に&をつけるとコンテナ内の要素を変更できる
    for(auto &i:a){
        m[i] ++;
    }

    int cnt=0;
    for(auto &i:m){
        if(i.first < i.second){
            cnt += i.second - i.first;
        }
        else if(i.first > i.second){
            cnt += i.second;
        }
    }
    cout << cnt << endl;


}