#include<cstdio>
#include<unordered_map>
using namespace std;
using ull = unsigned long long;

int main(){
    ull N, M;
    scanf("%llu %llu", &N, &M);
    unsigned ruiseki[N+1];
    ruiseki[0] = 0;
    for (unsigned i = 0; i < N; i++){
        unsigned tmp;
        scanf("%u", &tmp);
        ruiseki[i+1] = (ruiseki[i] + tmp) %M;
    }
    unordered_map<unsigned, ull> mod;
    for (unsigned i = 0; i <= N; i++){
        mod[ruiseki[i]]++;
    }
    ull answer = 0;
    for(auto i : mod) answer += i.second*(i.second - 1)>>1;
    printf("%llu\n", answer);
	return 0;
}