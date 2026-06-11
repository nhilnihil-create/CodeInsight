#include<cstdio>
unsigned prime[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}, over[5], divisor[5] = {3,5,15,25,75};

int main(){
    unsigned N;
    scanf("%u", &N);
    unsigned power, _N;
    for (size_t i = 0; i < 15; i++){
        power = 1, _N = N;
        while(_N /= prime[i]) power += _N;
        for (size_t j = 0; j < 5; j++){
            if(power >= divisor[j]) over[j]++;
        }
    }
    printf("%u\n", over[4] + over[3]*(over[0] - 1) + over[2]*(over[1] - 1) + (over[1]*(over[1] - 1)>>1)*(over[0] - 2));
	return 0;
}