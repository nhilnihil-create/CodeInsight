#include<bits/stdc++.h>
using namespace std;
using ul = unsigned long;
using ull = unsigned long long;
#define vec vector
#define rep(_i,_n) for(ull _i = 0; _i < _n; _i++)
#define rep2(_i,_s,_n) for(ull _i = _s; _i < _n; _i++)
#define elif else if
#define push(_a) push_back(_a)
#define fullSort(_a) sort(_a.begin(), _a.end())
#define inputVecI(_name, _n) vec<int> _name(_n);rep(_i, _n)cin >> _name[_i];
#define inputVecUL(_name, _n) vec<ul> _name(_n);rep(_i, _n)cin >> _name[_i];
#define inputVecULL(_name, _n) vec<ull> _name(_n);rep(_i, _n)cin >> _name[_i];
#define inputVecS(_name, _n) vec<string> _name(_n);rep(_i, _n)cin >> _name[_i];
#define printVec(_vec) cout << "{";rep(i, _vec.size()-1)cout << _vec[i] << ",";cout << _vec[_vec.size()-1];cout << "}\n";
#define append(_x) push_back(_x)
#define mapLoop(_i, _name) for(auto i = _name.begin(); i != _name.end(); i++)

int main()
{
    ul r, D, x;
    cin >> r >> D >> x;
    rep(i, 10){
      x = r * x - D;
      cout << x << endl;
    }
    return 0;
}
