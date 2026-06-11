#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <utility>
#define DIVCEIL(A,B) ((A+(B-1))/B)
using namespace std;
#define LL long long

void solve(long long N, std::vector<long long> a){
    auto me = max_element(a.begin(), a.end(), [](auto a, auto b){
        return abs(a)<abs(b);
    });
    vector<pair<LL, LL>> procs;
    LL ime = me-a.begin();
    if((*me) >= 0){
        for(LL i=0; i<N; i++){
            if(i==ime)continue;
            if(a[i]<0){
                a[i]+=(*me);
                procs.emplace_back(make_pair(ime, i));
            }
        }
        for(LL i=1; i<N; i++){
            if(a[i] < a[i-1]){
                a[i]+=a[i-1];
                procs.emplace_back(make_pair(i-1, i));
            }
        }
    }else{
        for(LL i=0; i<N; i++){
            if(i==ime)continue;
            if(a[i]>0){
                a[i]+=(*me);
                procs.emplace_back(make_pair(ime, i));
            }
        }
        for(LL i=N-2; i>=0; i--){
            if(a[i] > a[i+1]){
                a[i] += a[i+1];
                procs.emplace_back(make_pair(i+1, i));
            }
        }
    }
    cout << procs.size() << endl;
    for(auto p: procs){
        cout << p.first+1 << " " << p.second+1 << endl;
    }
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
