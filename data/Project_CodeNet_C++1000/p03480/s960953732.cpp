#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

template<typename T>
class BIT{
public:
    vector<T> bit;
    int size;
    BIT(int size):
        bit(vector<T>(size+1,0)),size(size){}
    
    T sum(int i){
        if(!i) return 0;
        return bit[i]+sum(i-(i&(-i)));
    }

    void add(int i,T x){
        if(i>size)return;
        bit[i]+=x;
        add(i+(i&(-i)),x); 
    }   
};

int main(){

    string S; cin >> S;

    int N = S.size();

    int ub = N+1;
    int lb = N/2;
    int K;

    while (ub-lb>1) {
        K = (ub+lb) / 2;
        BIT<int> bit(N+1);
        FOR(i,1,N+1){
            bit.add(i,(int)(S[i-1]-'0'));
            bit.add(i+1,(int)(S[i-1]-'0'));
        }
        FOR(i,1,N-K+1){
            if(bit.sum(i)%2) {
                bit.add(i,1);
                bit.add(N+1,1);
            }
        }
        FOR(i,K+1,N+1) {
            if(bit.sum(i)%2) {
                bit.add(1,1);
                bit.add(i+1,1);
            }
        }
        if(bit.sum(1)%2){
            bit.add(1,1);
            bit.add(K+1,1);
        }
        bool flag = true;
        FOR(i,N-K+1,K) {
            if (bit.sum(i)%2!=bit.sum(i+1)%2) flag = false;
        }
        if (flag) lb = K;
        else ub = K;
    }
    cout << lb << endl;
    return 0;
}