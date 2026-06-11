#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const long long INF=INT_MAX/4;
const long long MOD=998244353;
const double EPS=1e-14;
const bool DEBUG=false;

const string YES = "YES";
const string NO = "NO";
const string Yes = "Yes";
const string No = "No";

template<class T>
void debug(T head){
    if(DEBUG){
        cout<<head<<endl;
    }
}

template <class Head, class... Body>
void debug(Head head, Body... body){
    if(DEBUG){
        cout<<head<<" ";
        debug(body...);
    }
}

/////
void answer(string S, string T){
    int len = S.length();
    for(int i=0; i<len; ++i){
        S = S.substr(len - 1, 1) + S.substr(0, len - 1);
        if(S == T){
            cout<<Yes<<endl;
            return;
        }
    }
    cout<<No<<endl;
    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    string S, T;
    cin>>S>>T;
    answer(S, T);

    return 0;
}
