#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int binary_digit_one_num[100]; //i桁目の値が1の個数;


int main(){
    int N; 
    long long K;
    cin >> N >> K;

    vector<long long> a(N);

    for(int i=0; i<N; ++i){
        cin >> a[i];
    }

    //10進数を2進数にして、各桁で1があるところを記録
    for(int i=0; i<N; ++i){
        long long NUM = a[i];
        int keta = 0;
        int cnt = 0;

        while( NUM > 0 ){
            if(NUM&1){
                keta = cnt;
                binary_digit_one_num[keta]++;
            } 
            NUM >>= 1;
            cnt++;
        }
    }

    int max_keta = 0;
    int cnt = 0;
    long long k = K;
    while(k > 0){
        if(k & 1) max_keta = cnt;
        k >>= 1;
        cnt++;
    }

    long long candidate = 0;
    for(int keta=max_keta; keta>=0; --keta){
        if( N %2 == 0){
            // 0が多いので1を選択
            if( binary_digit_one_num[keta] < N/2 ){
                long long tmp = candidate + pow(2, keta);
                if(tmp <= K){
                    candidate = tmp;
                }
            }
        }else{
            // 0が多いので1を選択
            if( binary_digit_one_num[keta] < N/2 + 1 ){
                long long tmp = candidate + pow(2, keta);
                if(tmp <= K){
                    candidate = tmp;
                }
            }
        }
    }

    long long ans = 0;
    for(int i=0; i<N; ++i){
        ans += candidate ^ a[i];
    }

    cout << ans << endl;
}