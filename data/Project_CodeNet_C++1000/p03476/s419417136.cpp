
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//a[i]=iが2017に似た数なら1、違ければ0 を考えると累積和になる

int main(){
   //エラトステネスのふるい
    int MAX = 101010;
    vector<int> is_prime(MAX,1);
    is_prime[0]=0;
    is_prime[1]=0;
    for(int i=2; i<MAX; i++){
        if(!is_prime[i]) continue;
        for(int j=i*2; j<MAX; j+=i) is_prime[j]=0;
    }

    //2017に似た数かどうか
    vector<int> a(MAX,0);
    for(int i=0; i<MAX; i++){
        if(i % 2 == 0) continue; //偶数は与えられないし絶対素数じゃない
        if(is_prime[i] && is_prime[(i+1)/2]) a[i]=1;
    }

    //l<=x<=rで2017に似た数の総和はaの累積和を用いて高速に求められる
    vector<int> s(MAX+1,0);
    for(int i=0; i<MAX; i++) s[i+1] = s[i] + a[i];

    //クエリ処理
    int Q; 
    cin >> Q; //Q個のクエリが与えられる
    for(int q=0; q < Q; ++q){
        int l, r;
        cin >> l >> r;
        ++r; //今回のクエリではr自身も含むので+1する

        cout << s.at(r) - s.at(l) << endl;
    }
}