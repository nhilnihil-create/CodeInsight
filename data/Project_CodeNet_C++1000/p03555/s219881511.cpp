#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    vector<char> vec(100);
    rep(i,6){
        cin >> vec.at(i);
    }
    if(vec.at(0) == vec.at(5)&&vec.at(1) == vec.at(4)&&vec.at(2) == vec.at(3)) cout << "YES" << endl;
    else cout << "NO" << endl;
}