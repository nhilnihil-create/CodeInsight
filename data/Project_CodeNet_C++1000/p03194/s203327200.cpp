#include <iostream>  // for cout, cin
#include <stdio.h>   // for printf, scanf

using namespace std;
typedef long long ll;
/*
 * 計算クラス
 */
class Calc
{
    // 宣言
    ll a;

    public:
        // 素因数分解
        void decompositPrime(ll a,ll b);
};

/*
 * 素因数分解
 */
void Calc::decompositPrime(ll n,ll number)
{
if(number!=1){
ll re=1;
    // 割る数の初期値
    a = 2;
    // √n ≧ a ( n ≧ a * a ) の間ループ処理
ll count=0;
    while (n >= a * a) {
        // a で割り切れたら、a は素因数
        // そして、割られる数を a で割る
        // a で割り切れなかったら、 a を 1 増加させる
        if (n % a == 0) {
count++;
//cout<<n<<" "<<a<<" "<<endl;
 //printf("%d * ", a);
            n /= a;
if(count==number){
re=re*a;
count=0;
}
        } else {
if(count>=number){
re=re*a;
}
count=0;
            a++;
        }
    }
    // 最後に残った n は素因数
   //printf("%d\n", n);
if(n==a)
count++;
if(count>=number){
re=re*a;
}
cout<< re;
}
else {
cout<<n;
}

}


/*
 * メイン処理
 */
int main()
{
    ll  iNum,n;

        // 計算クラスインスタンス化
        Calc objCalc;


            // 自然数入力
            cin  >> n>>iNum;
            // 素因数分解
            objCalc.decompositPrime(iNum,n);

  

    return 0;
}