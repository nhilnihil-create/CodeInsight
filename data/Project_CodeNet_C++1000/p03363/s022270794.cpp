#include <iostream>
#include <map>

using namespace std;
map<long long, long long> S;
void print(){
    map<long long, long long>::iterator it;
    long long ans=0;
    for(it=S.begin();it!=S.end();it++){
        pair<long long, long long> item=*it;
        ans += item.second*(item.second-1)/2;
    }
    cout << ans << endl;
}

int main(){
    long long N, sum=0;
    long long A[200000];

    S[0] = 1;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
        S[sum]++;
    }
    print();
    return 0;
}