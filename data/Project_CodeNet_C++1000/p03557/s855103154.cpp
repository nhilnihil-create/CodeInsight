#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(ll i=0; i<(ll)(n); i++)
#define REPM(i,n) for(ll i=(n); 0<=i; i--)
#define VI vector<int>
#define VL vector<ll>
#define VD vector<double>
#define VS vector<string>
#define V_SORT_U(x) sort(x.begin(), x.end());                   //昇順
#define V_SORT_D(x) sort(x.begin(), x.end(),greater<int>());    //降順
#define V_SUM(x) accumulate(x.begin(), x.end(), 0)
#define STR_TRANS_UP(x) transform(x.begin(), x.end(), x.begin(), ::toupper); 
#define STR_TRANS_LOW(x) transform(x.begin(), x.end(), x.begin(), ::tolower);
#define SetPre(x) setprecision(x)

int main(void){
    //標準入力
    ll N;
    cin >> N;
    VL A(N),B(N),C(N);
    REP(i,N)
    {
        cin >> A.at(i);
    }
    REP(i,N)
    {
        cin >> B.at(i);
    }
    REP(i,N)
    {
        cin >> C.at(i);
    }
    //昇順ソートしておく
    V_SORT_U(A)
    V_SORT_U(B)
    V_SORT_U(C)
    //中パーツを固定⇒上下パーツで使える数をカウントする
    ll count = 0;
    REP(i,N)
    {
        auto itr_A = lower_bound( A.begin(), A.end(), B.at(i) ); //lowerで以上となる数を数えて全ての数から引く
        auto itr_C = lower_bound( C.begin(), C.end(), B.at(i)+1 ); //lowerは以上なので+1して判定する（真に大きくするため）
        ll increment = 0;
        //cout << "*itr_A:" << *itr_A << endl;
        //cout << "*itr_C:" << *itr_C << endl;
        increment = (itr_A-A.begin())*(C.end()-itr_C); //上パーツ候補数×下パーツ数の組み合わせ
        
        //cout << "debug increment:" << increment << endl;
        count += increment; //上パーツ候補数×下パーツ数の組み合わせ
    }

    cout << count << endl;
    return 0;
}