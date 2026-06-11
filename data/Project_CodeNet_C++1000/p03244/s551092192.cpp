#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N;
    cin >> N;
    map<int,int> mp_odd,mp_even;
    vector<int> A(N);
    bool f = true;
    int bf;
    rep(i,N){
        cin >> A[i];
        if(i==0) bf = A[i];
        else if(bf!=A[i]) f=false;
        if(i%2!=0){
            mp_odd[A[i]]++;
        }else{
            mp_even[A[i]]++;
        }
    }
    // すべての数が一緒の場合
    if(f){
        cout << N/2 << endl;
        return 0;
    }

    int odd_memo=0,odd_memo2=0;
    int even_memo=0,even_memo2=0;
    int odd_1st = -1;
    int odd_2nd = -1;
    int even_1st = -1;
    int even_2nd = -1;
    rep(i,N){
        if(i%2!=0){
            if(odd_1st<mp_odd[A[i]]){
                odd_1st = mp_odd[A[i]];
                odd_memo = A[i];
            }
        }else{
            if(even_1st<mp_even[A[i]]){
                even_1st = mp_even[A[i]];
                even_memo = A[i];
            }
        }
    }
    if(odd_memo!=even_memo){
        cout << N - odd_1st - even_1st << endl;
        return 0;
    }
    // 最頻値が同じときは2番目の数を候補にする
    mp_odd[odd_memo]=-1;
    mp_even[even_memo]=-1;
    rep(i,N){
        if(i%2!=0){
            if(odd_2nd<mp_odd[A[i]]){
                odd_2nd = mp_odd[A[i]];
                odd_memo2 = A[i];
            }
        }else{
            if(even_2nd<mp_even[A[i]]){
                even_2nd = mp_even[A[i]];
                even_memo2 = A[i];
            }
        }
    }
    // 2番目の最頻値が多いほうを2番目にそろえる
    if(odd_2nd>even_2nd){
        cout << N - even_1st - odd_2nd << endl;
    }else if(odd_2nd<even_2nd){
        cout << N - even_2nd - odd_1st << endl;
    }else{
        // 2番目も同じ場合はどっちでもいい
        cout << N - even_1st - odd_2nd << endl;
    }
    return 0;
}