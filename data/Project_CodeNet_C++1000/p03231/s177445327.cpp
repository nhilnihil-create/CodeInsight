#include<iostream>
using namespace std;

long long fpb(long long a, long long b){
    if(b == 0) return a;
    return fpb(b, a%b);
}

long long findkpk(long long a, long long b){
    return a*b/fpb(a,b);
}

int main(){
    bool correct = true;
    int N, M;
    string  S, T;

    cin >> N >> M >> S >> T;

    long long kpk = findkpk(N, M);
    long long sub1 = kpk/N, sub2 = kpk/M;
    long long subkpk = findkpk(sub1, sub2);

    for(long long i=0; i<kpk ; i+=subkpk){
        if(S[i/sub1] != T[i/sub2]){
            correct = false;
            break;
        }
    }

    if(correct){
        cout << kpk << endl;
    } else{
        cout << -1 << endl;
    }
}