#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll h,w;cin>>h>>w;
    vector<vector<char>> s(52,vector<char>(52));
    //読み込み
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>s[i][j];
        }
    }
    ll count=0;
    for(int i=1;i<=h;i++){
        for(int j=1; j<=w; j++){
            if(s[i][j]=='#'&&s[i][j-1]=='.'&&s[i-1][j]=='.'&&s[i+1][j]=='.'&&s[i][j+1]=='.'){
                count++;
            }
        }
    }
    if(count>0){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
    
    return 0;
}
