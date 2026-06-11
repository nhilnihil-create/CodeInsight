#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<functional>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    vector<long long> B;
    for(int i=0; i<N; i++){
        long long r = A.at(i);
        B.push_back(r);
        for(int j=i+1; j<N; j++){
            r += A.at(j);
            B.push_back(r);
        }
    }
    vector<int> a;
    for(int i=41; i>-1; i--){
        long long x = 1LL << i;
        vector<long long> n;
        for(auto it=B.begin(); it != B.end(); ++it){
            if((*it & x) == x){
                n.push_back(*it);
            }
        }
        if(n.size() >= K){
            a.push_back(i);
            B = n;
            break;
        }
    }
    if(a.empty()){
        cout << 0 << endl;
        return 0;
    }
    for(int i=a.at(0)-1; i>-1; i--){
        vector<long long> n;
        long long x = 1LL << i;
        for(auto it=B.begin(); it != B.end(); ++it){
            if((*it & x) == x){
                n.push_back(*it);
            }
        }
        if(n.size() >= K){
            a.push_back(i);
            B = n;
        }
    }
    long long r = 0;
    for(auto it=a.begin(); it != a.end(); ++it){
        r += (1LL << *it);
    }
    cout << r << endl;
}

