
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//毎回合計が２ずつ増えていく
//A,B,C→X,X,Xなら(3X-(A+B+C))/2が答え
//3X=A+B+C(mod2)
//X>=max{A,B,C}
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int m=max(a,max(b,c));
    int ans=0;
    if(m%2==(a+b+c)%2){
        ans = (3*m-a-b-c)/2;
        cout << ans << endl;
        return 0;
    }
    else{
        m += 1;
        ans = (3*m-a-b-c)/2;
        cout << ans << endl;
        return 0;
    }
}