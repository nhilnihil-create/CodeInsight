#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> A(N);
    
    map<int64_t,int64_t> m;
    
    for ( int64_t i = 0; i < N; ++i){
        cin >> A.at(i);
        m[A.at(i)] = m[A.at(i)] + 1;
    }
    
    vector<int64_t> B(M), C(M);
    for ( int64_t i = 0; i < M; ++i){
        cin >> B.at(i) >> C.at(i);
        m[C.at(i)] = m[C.at(i)] + B.at(i);
    }
    
    
    vector<int64_t> v;
    vector<int64_t> n;
    int64_t value, num;
    for ( auto p: m ){
        value = p.first;
        num = p.second;
        v.push_back(value);
        n.push_back(num);
        //cout << "val " << value << " num " << num << endl;;
    }
    
    int64_t num_all = 0;
    int64_t val_all = 0;
    for ( int64_t i = v.size() - 1; i >= 0; --i){
        value = v[i];
        num = n[i];
        if ( num_all + num >= N ){
            val_all = val_all + value * ( N - num_all ) ;
            break;
        } else {
            val_all = val_all + value * num;
            num_all = num_all + num;
        }
        //cout << "i " <<  i << " val " <<  val_all << " num " << num_all << endl;
    }
    
    cout << val_all << endl;
    
    return 0;
}
