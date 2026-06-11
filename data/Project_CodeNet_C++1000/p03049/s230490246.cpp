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
void answer(ll N, vector<string> &s){
    ll answer = 0;
    ll x = 0, y = 0, z = 0;
    for(auto ss : s){
        int len = ss.length();
        for(int i=0; i<len - 1; ++i){
            if(ss.substr(i, 2) == "AB"){
                answer++;
            }
        }
        if(ss[0] == 'B' && ss[len - 1] == 'A'){
            z++;
        }else if(ss[0] == 'B'){
            x++;
        }else if(ss[len - 1] == 'A'){
            y++;
        }
    }
    debug(answer);
    debug(x, y, z);
    if(z>0){
        answer += z-1;
        // if(x != y){
        if(x + y > 0){
            answer++;
        }
    }
    answer += min(x, y);
    cout<<answer<<endl;
    return;
}

/////

int main(int argc, char* argv[]){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout.precision(16);

    ll N;
    cin>>N;
    vector<string> s(N);
    for(auto &ss : s){
        cin>>ss;
    }
    answer(N, s);

    return 0;
}
