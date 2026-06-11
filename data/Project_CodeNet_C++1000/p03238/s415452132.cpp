#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if(N==1) cout << "Hello World\n";
    else{
        int a,b;
        cin >> a >> b;
        cout << a+b << "\n";
    }
}