#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<functional>
using namespace std;

int main(){
    long N, H;
    cin >> N >> H;
    vector<long> A(N);
    vector<long> B(N);
    for(long i=0; i<N; i++){
        cin >> A.at(i) >> B.at(i);
    }
    auto amax = max_element(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<long>());
    long c = 0;
    long r = 0;
    for(auto i=B.begin(); i<B.end(); i++){
        if (*amax >= *i){
            break;
        }
        c += *i;
        r++;
        if(c >= H){
            break;
        }
    }
    if(c < H){
        r += long(ceil(double(H-c)/ double(*amax)));
    }
    cout << r << endl;
}
