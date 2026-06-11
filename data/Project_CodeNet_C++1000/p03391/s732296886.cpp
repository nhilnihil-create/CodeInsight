#include <bits/stdc++.h>

using namespace std;

#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define mk make_pair

typedef long long LL;
typedef pair<int,int> pi;

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

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& v){
    os << v.first <<" "<<v.second<<endl;
    return os;
}

const int maxn = 2e5+5;
int N;


int main()
{
    cin >> N;
    LL ans = 0;
    LL minb = 1e9 + 7;
    int ok = 0;
    _for(i,0,N){
        LL a,b;
        cin >> a >> b;
        if(a != b) ok = 1;
        ans += a;
        if(a > b) minb = min(b,minb);
    }
    if(!ok){
        cout << 0 << endl;
        return 0;
    }

    cout << ans - minb << endl;
    return 0;
}
