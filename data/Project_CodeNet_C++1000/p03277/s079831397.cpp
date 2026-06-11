#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<long, long> P;

long bit[100001];
long a[100001];
long N;

long sum(long i){
    long s = 0;
    while(i > 0){
        s += bit[i];
        i-= i&-i;
    }
    return s;
}

void add(long i, long x){
    while(i <= N+1){
        bit[i] += x;
        i += i & -i;
    }
}

long count(long c){
    P b[100001];
    b[0] = P(0, 0);
    for(long i = 1; i <= N; i++){
        b[i].second = i;
        if(a[i] > c) b[i].first = b[i-1].first+1;
        else b[i].first = b[i-1].first-1;
        //cout << b[i].first << ' ';
    }
    //cout << endl;
    sort(b, b+N+1);
    long tmp = 0;
    memset(bit, 0, 100001*sizeof(long));
    for(long i = 0; i <= N; i++){
        tmp += sum(b[i].second+1);
        add(b[i].second+1, 1);
    }
    return tmp;
}

int main(){
    cin >> N;
    long M = (N*(N+1))/2;
    for(long i = 1; i <= N; i++) cin >> a[i];
    if(N == 1){
        cout << a[1] << endl;
        return 0;
    }
    long l  = 0;
    long r = 1000000001;
    while(r-l>1){
        long c = (r+l)/2;
        //cout << "c:" << c << endl;
        //cout << "l:" << l << " r:" << r <<endl;
        long tmp1 = count(c-1);
        long tmp2 = count(c);
        //cout << "tmp1:" << tmp1 << " tmp2:" << tmp2 <<endl;
        if(tmp1*(long)2 >= M && tmp2*(long)2 < M){
            cout << c << endl;
            //cout << tmp1 << ' ' << tmp2 << endl;
            //cout << count(0) << ' ' << count(10) << endl;
            return 0;
        }
        else if(tmp1 < M/2) r = c;
        else l = c;
    }
    //cout << l << endl;
}