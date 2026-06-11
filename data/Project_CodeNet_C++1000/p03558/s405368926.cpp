#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int K; cin >> K;
    vector<int> d(K, INF);
    queue<int> que;
    que.push(1);
    d[1] = 1;

    int j = 1;
    while(true){
        j = (j * 10) % K;
        if(d[j] < INF){
            break;
        }else{
            d[j] = d[1];
            que.push(j);
        }
    }

    while(!que.empty()){
        int i = que.front(); que.pop();
        if(i == 0) break;
        j = (i + 1) % K;
        if(d[j] < INF) continue;
        d[j] = d[i] + 1;
        que.push(j);
        while(true){
            j = (j * 10) % K;
            if(d[j] < INF){
                break;
            }else{
                d[j] = d[i] + 1;
                que.push(j);
            }
        }
    }

    cout << d[0];
    
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}