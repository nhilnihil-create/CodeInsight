
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

//x以下で最大の冪乗数(b^p)を求めたい
int main(){
    int x; cin >> x;
    //iがb^p(求めたい数)にあたる
    for(int i=x; i>=1; i--){
        int n=i;
        //iが1に到達してしまったら冪乗数はなかったということ
        if(i==1){
            cout << i << endl;
        }
        //jがbにあたる　jは最大でもnの平方根以下
        //冪乗数では次数は2でも3でも関係ないので割り続ければ良い
        for(int j=2;j*j<=n;j++){
            while(n%j==0){
                n /= j;
            }
            //1つの数で割り続けた結果が1になるならその数の冪乗と言える
            if(n==1){
                cout << i << endl;
                i=1;
            }
            n=i;
        }
    }


}