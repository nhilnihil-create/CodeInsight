#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#define DBL_MIN 0.000000000000001
using namespace std;

long euclid(long a,long b){
    long big = max(a,b);
    long small  =min(a,b);
    while(big % small){
        long amari = big%small;
        big = small;
        small = amari;
    }
    return small;
}

long euclidean_gcd(long a, long b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}

int main(void){
    vector<long> mati;

    long N,X;
    cin >> N >> X;
    for(long i =0; i < N; i++){
        long tmp;
        cin >> tmp;
        long dis = abs(tmp -X);
        mati.push_back(dis);
    }
    sort(mati.begin(), mati.end());

    if(N == 1){
        cout <<  mati[0] << endl;
        return 0;
    }

    long minstep = *(mati.end()-1);
    long begin = 0;
    for(long i =0; i < mati.size()-1; i++){
        long step = mati[i+1] - mati[i];
        if(step < minstep && step != 0){
            minstep = step;
            begin = mati[i];
        }
    }

    long neko = euclidean_gcd(minstep,begin);
    
    for(long i =0; i < mati.size(); i++){
        if(mati[i] % neko){
            neko = euclidean_gcd(mati[i],neko);
        }
    }
    cout << neko << endl;
}