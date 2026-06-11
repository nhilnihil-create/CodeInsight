#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define DEBUG

#define _GLIBCXX_DEBUG
#ifdef DEBUG
#define s(...) show(__VA_ARGS__);
#define sl(...) show(__VA_ARGS__);cout<<endl;
#else
#define s(...)
#define sl(...)
#endif
void show() {}
template <class Head,class... Args>void show(Head t,Args... args){std::cout<<t<<" ";show(args...);}
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define REPR(i, n) for(ll i = n; i >= 1; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define INF 1e9+123
#define ALL(v) v.begin(), v.end()

int main(){
    string X;
    cin>>X;
    
    int Y=stoi(X.substr(0,4));
    int M=stoi(X.substr(5,7));
    int D=stoi(X.substr(8,10));
    if(Y<2019){
        cout<<"Heisei";return 0;
    }else if(Y>2019){
        cout<<"TBD";return 0;
    }else{
        if(M<=4){
            cout<<"Heisei";return 0;
        }else if(M>4){
            cout<<"TBD";return 0;
        }
    }
    //if(equal(D.begin(), D.end()-1, K.begin()))cout<<"Yes";else cout<<"No";
    return 0;
}
