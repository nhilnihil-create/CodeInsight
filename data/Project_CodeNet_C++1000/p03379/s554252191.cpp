#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    unsigned N;
    scanf("%u", &N);
    unsigned X[N], _X[N];
    for(int i = 0; i < N; ++i){
        scanf("%u", X + i);
        _X[i] = X[i];
    }
    sort(_X, _X + N);
    for (size_t i = 0; i < N; i++){
        printf("%u\n", (X[i] >= _X[N>>1]) ? _X[(N>>1)-1] : _X[N>>1]);
    }
	return 0;
}