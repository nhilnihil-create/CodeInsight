#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll;

template <class T1, class T2>
using dict = std::unordered_map<T1, T2>;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if (A==B && B==C) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}