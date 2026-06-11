#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    string s;
    cin >> s;
    int K,n;
    cin >> K;
    n = s.length();
    set<string> st;
    char ch = 'a';
    for(int i = 0; i <= 25; i++){
        char temp = ch + i;
        for(int j = 0; j < n; j++){
            if(s[j] == temp){
                string T = string() + s[j];
                st.insert(T);
                for(int m = 1; m < K; m++){
                    if(j+m < n){
                        T += s[j+m];
                        st.insert(T);
                    }
                }
            }
        }
        if(st.size() > K) break;
    }
    auto ite = st.begin();
    int count = 1;
    string ans;
    for(; ite != st.end(); ite++){
        if(count == K){
            ans = *ite;
            break;
        }
        count++;
    }
    cout << ans << endl;
    return 0;
}
