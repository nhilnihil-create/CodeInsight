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

const int maxn = 3e4+5;

int can[maxn];
set<int> si;

int main()
{
    int cnt = 0;
    LL temp;
    _rep(i,1,30000){
        if(!(i%2)||!(i%3)){
            can[i] = 1;
        }
    }

    int N;
    cin >> N;

    if(N == 3){
        printf("2 5 63\n");
        return 0;
    }

    vector<int> even = {2,10,3,9,4,8,6,12};
    vector<int> odd =  {6,2,10,3,9,4,8,12};

    vector<int> us;
    vector<int> ans;
    if(N%2) us = odd;
    else us = even;

    cnt = 0;
    int ok = 0;
    _for(k,0,(30000/12)){
        _for(j,0,8){
            ans.push_back(k*12 + us[j]);
            cnt++;
            if(cnt == N) {ok = 1;break;}
        }
        if(ok) break;
    }

    _for(i,0,ans.size()){
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}
