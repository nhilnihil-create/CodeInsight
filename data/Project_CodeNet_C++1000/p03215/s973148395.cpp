#include<iostream>
#include<unordered_set>
using namespace std;

int N, K;
long long a[1000], sum[1001];
unordered_multiset<long long> sums;

int find_next_max_bit(int now_max_bit){
    int bit_cnt[40] = {};
    for(auto itr = sums.begin(); itr != sums.end(); itr++){
        for(int bit = 0; bit < now_max_bit; bit++){
            if((*itr) & (1LL << bit)){
                bit_cnt[bit]++;
            }
        }
    }
    for(int i = now_max_bit - 1; i >= 0; i--){
        if(bit_cnt[i] >= K){
            return i;
        }
    }
    return -1;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    // sum(a[i: j])
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j <= N; j++){
            sums.insert(sum[j] - sum[i]);
        }
    }

    long long ret = 0;
    int now_bit = find_next_max_bit(40);
    while(now_bit != -1){
        ret += (1LL << now_bit);
        unordered_multiset<long long> tmp;
        for(auto itr = sums.begin(); itr != sums.end(); itr++){
            if((*itr) & (1LL << now_bit)){
                tmp.insert(*itr);
            }
        }
        sums = tmp;
        now_bit = find_next_max_bit(now_bit);
    }
    cout << ret << endl;

}