#include <bits/stdc++.h>
using namespace std;

bool DEBUG = false;

int main(int argc, char** argv, char** envp) {
    if(argc == 2 && strcmp(argv[1], "--debug") == 0) {
        DEBUG = true;
    }
    int N;
    scanf("%d", &N);
    vector<int> L, R;
    L.resize(N);
    R.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &L[i], &R[i]);
    }
    sort(L.begin(), L.end()); reverse(L.begin(), L.end());
    sort(R.begin(), R.end());
    long long has = 0, tmp;
    tmp = 0;
    for(int i = 0; i < N; i++) {
        tmp -= (long long)R[i]; has = max(has, tmp);
        tmp += (long long)L[i]; has = max(has, tmp);
    }
    tmp = 0;
    for(int i = 0; i < N; i++) {
        tmp += (long long)L[i]; has = max(has, tmp);
        tmp -= (long long)R[i]; has = max(has, tmp);
    }
    printf("%lld\n", has*2);
}
