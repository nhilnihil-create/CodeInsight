#include<iostream>
using namespace std;

long long N, a[100000];
int bit[1000010];

void add(int a, int w){
    for(int x = a; x <= N+100001; x += x & -x) bit[x] += w;
}
int sum(int a){
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

bool judge(int x){
    int S[100001] = {};
    for(int i = 0; i <= 200010; i++){
        bit[i] = 0;
    }
    long long cnt = 0;
    add(0+100001, 1);
    for(int i = 1; i <= N; i++){
        S[i] = S[i-1] + (a[i-1] >= x ? 1 : -1);
        cnt += sum(S[i]+100001);
        add(S[i]+100001, 1);
    }
    return cnt >= (N*(N+1)/2 + 1)/2;

}


// begin: ok, end: ng
int binary_search(int begin, int end){
    if(end - begin <= 1){
        return begin;
    }
    int mid = (begin + end) / 2;
    if(judge(mid)){
        return binary_search(mid, end);
    }else{
        return binary_search(begin, mid);
    }
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cout << binary_search(1, 1000000001) << endl;
}
