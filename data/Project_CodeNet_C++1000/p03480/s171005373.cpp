#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define LL long long

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v) {
    _for(i,0,v.size()) os << v[i] << " ";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os,const set<T>& v){
    for(typename set<T>::iterator it = v.begin();it != v.end();it++)
    os << *it <<" ";
    return os;
}

string s;

int main()
{
    cin >> s;
    int sz = s.size();
    int ans1 = sz;
    _for(i,0,sz-1){
        if(s[i] != s[i+1]) ans1 = min(ans1,max(sz-(i+1),i+1));
    }

    cout << ans1 << endl;
    return 0;
}
