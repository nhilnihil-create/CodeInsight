#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct Edge{
    ll to, weight;
    Edge(ll t, ll w) : to(t), weight(w){}
};
using graph = vector<vector<ll>>;
using Graph = vector<vector<Edge>>;


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    string s;
    cin>>s;

    vector<ll> alp(26, 0);
    for(ll i=0;i<s.size();++i){
        alp[s[i]-'a']++;
    }
    char letter;
    if(s.size() != 26){
        for(ll i=0;i<26;++i){
            if(alp[i] == 0){
                letter = i+'a';
                cout<<s + letter<<endl;
                return 0;
            }
        }
    }else{
        for(ll i=25;i>=0;--i){
            for(ll j=s[i]+1;j<='z';++j){
                if(alp[j-'a'] == 0){
                    s[i] = j;
                    s = s.substr(0, i+1);
                    cout<<s<<endl;
                    return 0;
                }
            }
            alp[s[i]-'a'] = 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}