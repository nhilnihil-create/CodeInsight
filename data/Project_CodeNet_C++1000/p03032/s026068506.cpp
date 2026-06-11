#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    unsigned N, K;
    scanf("%u %u", &N, &K);
    int V[N];
    for(int i = 0; i < N; ++i){
        scanf("%d", V + i);
    }
    unsigned take_out_max = min(N, K);
    int ruiseki[N+1];
    ruiseki[0] = 0;
    for (size_t i = 0; i < N; i++){
        ruiseki[i+1] = ruiseki[i] + V[i];
    }
    int answer = 0;
    for (size_t take_out_from_left = 0; take_out_from_left <= take_out_max; take_out_from_left++){
        int take_out[take_out_max];
        for (size_t tmp = 0; tmp < take_out_from_left; tmp++){
            take_out[tmp] = V[tmp];
        }
        for (size_t take_out_from_right = 0; take_out_from_left + take_out_from_right <= take_out_max; take_out_from_right++){
            if(take_out_from_right) take_out[take_out_from_left + take_out_from_right - 1] = V[N - take_out_from_right];
            sort(take_out, take_out + take_out_from_left + take_out_from_right);
            int candidate = ruiseki[take_out_from_left] + ruiseki[N] - ruiseki[N - take_out_from_right];
            unsigned n_put_back = 0;
            while(n_put_back + take_out_from_left + take_out_from_right < K && n_put_back < take_out_from_left + take_out_from_right && take_out[n_put_back] < 0){
                candidate -= take_out[n_put_back];
                n_put_back++;
            }
            if(candidate > answer) answer = candidate;
        }
    }
    printf("%d\n", answer);
	return 0;
}